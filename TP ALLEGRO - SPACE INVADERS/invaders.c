#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdlib.h>
#include <time.h>

//----Definição de Tamanhos----//
const int WINDOW_W = 1280;
const int WINDOW_H = 720;
int SCREEN_W;
int SCREEN_H;
const int GRASS_H = 60;

const int NAVE_W = 100;
const int NAVE_H = 50;

const int ALIEN_W = 51;
const int ALIEN_H = 31;
//-----------------------------//

//-----Quantidade de Aliens----//
int E_LINHAS;
int E_COLUNAS;
//-----------------------------//

//---------Velocidades---------//
int NAVE_VEL = 5;
float ALIEN_X_VEL;
const int TIRO_VEL = 9;
//-----------------------------//

const float FPS = 60; 

//--Structs (nave, alien...)--//
typedef struct Nave {
	float x; //Coordenada x do meio da nave
	float y_base; //Coordenada y da base da nave
	float vel; //Quantidade de pixels "pulados" a cada update da nave
	ALLEGRO_COLOR cor;
	int dir, esq; //Estados de movimentação, se 1, se move para tal, se 0, não se move
} Nave;
typedef struct Alien {
	float x, y; //Coordenadas (x,y) do ponto mais acima e a esquerda do alien
	float x_vel, y_vel; //Quantidade de pixels "pulados" a cada update do alien
	int state; //Estado do alien, se 1, o alien está vivo e deve ser desenhado e movimentado, se 0 deve ser apagado
	int idx; //Tipo do alien
	ALLEGRO_COLOR cor;
} Alien;
typedef struct Tiro {
	float vel, x, y;
	int state;
	ALLEGRO_COLOR cor;
} Tiro;
//----------------------------//

//--------Funções Nave--------//
void initNave(Nave *nave) {
	//Adiciona os valores específicos à nave criada
	nave->x = SCREEN_W/2;
	nave->y_base = SCREEN_H - (GRASS_H * 2/3);
	nave->vel = NAVE_VEL;
	nave->dir = 0;
	nave->esq = 0;
	nave->cor = al_map_rgb(0, 51, 204);
}
void draw_nave(Nave nave, ALLEGRO_BITMAP *nave_img, int offset_x, int offset_y) {
    if (nave_img != NULL) {
        al_draw_bitmap(
            nave_img, 
            offset_x + nave.x - (NAVE_W / 2),
            offset_y + nave.y_base - NAVE_H,
            0
        );
	}
}
void update_nave(Nave *nave) {
	//se o botão estiver pressionado e a nave puder se mover (limites de tela) nave se move
	if(nave->dir == 1 && nave->x + NAVE_W/2 + NAVE_VEL <= SCREEN_W) {
		nave->x += NAVE_VEL;
	}
	if(nave->esq == 1 && nave->x - NAVE_W/2 - NAVE_VEL > 0) {
		nave->x -= NAVE_VEL;
	}
}
//----------------------------//

//-------Funções Alien -------//
void initAlien(Alien *alien) {
	//Adiciona valores específicos ao alien criado
	alien->x = 0;
	alien->y = 0;
	alien->x_vel = ALIEN_X_VEL;
	alien->y_vel = ALIEN_H; 
	alien->state = 1;
	alien->cor = al_map_rgb(rand()%256, rand()%256, rand()%256);
}
void draw_alien(Alien alien, ALLEGRO_BITMAP* tipos_aliens[], int offset_x, int offset_y) {
	//Se o alien estiver vivo, desenhe-o
	if (alien.state == 1) {
		if(tipos_aliens[alien.idx] != NULL) {
            // Desenha a imagem
            al_draw_bitmap(tipos_aliens[alien.idx], alien.x + offset_x, alien.y + offset_y, 0);
		}
	}
}
void update_alien(Alien *alien) {
	//Se o alien estiver tocando alguma das bordas, mude sua direção e desça-o
	if (alien->x + ALIEN_W + alien->x_vel > SCREEN_W || alien->x + alien->x_vel < 0) {
		alien->y += alien->y_vel;
		alien->x_vel *= -1;
	}

	alien->x += alien->x_vel;
}
int colisao_alien_solo(Alien alien) {
	//Se o alien estiver tocando o solo, encerre o jogo
	if(alien.state == 1 && alien.y + ALIEN_H >= SCREEN_H - GRASS_H) {
		printf("CAS - Coordenadas Alien: (%.2f, %.2f)", alien.x, alien.y);
		return 1;
	}
	else {
	return 0;
	}
}
//----------------------------//

//----Funções Vetor Aliens----//
void initAliens(Alien *alien, Alien aliens[E_LINHAS][E_COLUNAS]) {
	//Adiciona valores a cada um dos aliens de um vetor bidimensional
    for (int l = 0; l < E_LINHAS; l++) {
        for (int c = 0; c < E_COLUNAS; c++) {
            aliens[l][c].x = alien->x + (c * (ALIEN_W + 30));
            aliens[l][c].y = alien->y + (l * (ALIEN_H + 30));
            aliens[l][c].x_vel = alien->x_vel;
            aliens[l][c].y_vel = alien->y_vel;
			aliens[l][c].state = alien->state;
            aliens[l][c].cor = al_map_rgb(rand() % 256, rand() % 256, rand() % 256);
			aliens[l][c].idx = rand() % 6;
        }
    }
}
void draw_aliens(Alien aliens[E_LINHAS][E_COLUNAS], ALLEGRO_BITMAP* tipos_aliens[], int offset_x, int offset_y) {
	//Desenha todos os aliens do vetor se eles estiverem vivos
	for (int l = 0; l < E_LINHAS; l++) {
		for (int c = 0; c < E_COLUNAS; c++) {
			if (aliens[l][c].state == 1) {
				draw_alien(aliens[l][c], tipos_aliens, offset_x, offset_y);
			}	
		}
	}
}
void update_aliens(Alien aliens[E_LINHAS][E_COLUNAS], Alien *alien, ALLEGRO_SAMPLE *alien_sound) {
	//Se algum dos aliens estiver tocando uma das bordas da tela, mude a direção de todos e desça-os
	int brk = 0;
	for (int l = 0; l < E_LINHAS; l++) {
		for (int c = 0; c < E_COLUNAS; c++) {
			if (aliens[l][c].state == 1 && (aliens[l][c].x + ALIEN_W + alien->x_vel > SCREEN_W || aliens[l][c].x + alien->x_vel < 0)) {
				al_play_sample(alien_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				for (int l = 0; l < E_LINHAS; l++) {
					for (int c = 0; c < E_COLUNAS; c++) {
						aliens[l][c].y += alien->y_vel;
					}
				}
				alien->x_vel *= -1;
				brk = 1;
				break;
			}
		}
		if (brk == 1) {
			break;
		}
	}

	for (int l1 = 0; l1 < E_LINHAS; l1++) {
		for (int c1 = 0; c1 < E_COLUNAS; c1++) {
			if (aliens[l1][c1].state == 1) {
				aliens[l1][c1].x += alien->x_vel;
			}
		}
	}
}		
int colisao_aliens_solo(Alien aliens[E_LINHAS][E_COLUNAS]) {
	//Se algum alien tocar o chão o jogo acaba
	for (int l = 0; l < E_LINHAS; l++) {
		for (int c = 0; c < E_COLUNAS; c++) {
			if (colisao_alien_solo(aliens[l][c]) == 1) {
				return 1;
			}
		}
	}
	
	return 0;
}
int colisao_aliens_nave(Nave *nave, Alien aliens[E_LINHAS][E_COLUNAS]) {
    for (int l = 0; l < E_LINHAS; l++) {
        for (int c = 0; c < E_COLUNAS; c++) {
            if (aliens[l][c].state == 1) {
                // Verifica se a base do alien atingiu o topo da nave
                if (aliens[l][c].y + ALIEN_H >= nave->y_base - NAVE_H) {
                    // Verifica sobreposição horizontal
                    if ((aliens[l][c].x + ALIEN_W >= nave->x - NAVE_W/2) && 
                        (aliens[l][c].x <= nave->x + NAVE_W/2)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int verifica_state_aliens(Alien aliens[E_LINHAS][E_COLUNAS]) {
	for (int l = 0; l < E_LINHAS; l++) {
		for (int c = 0; c < E_COLUNAS; c++) {
			if(aliens[l][c].state == 1) {
				return 0;
			}
		}
	}
	return 1;
}
//----------------------------//

//--------Funções Tiros-------//
void initTiro(Tiro *tiro, Nave *nave) {
	//Adiciona valores para o tiro
	tiro->vel = TIRO_VEL;
	tiro->state = 0;
	tiro->cor = al_map_rgb(255,140,0);
}
void dispara_tiro(Tiro *tiro, Nave *nave, ALLEGRO_SAMPLE *tiro_sound) {
    if (tiro->state == 0) {  // Só dispara se não houver tiro ativo
        tiro->x = nave->x;  // Centraliza na nave
        tiro->y = nave->y_base - NAVE_H - 10;  // Posiciona acima da nave
        tiro->state = 1;
		al_play_sample(tiro_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}
void update_tiro(Tiro *tiro) {
	if (tiro->state == 1) {
		tiro->y -= tiro->vel;
	}
	if (tiro->y <= 0) {
		tiro->state = 0;
	}
}
void draw_tiro(Tiro *tiro, Nave *nave, ALLEGRO_BITMAP *tiro_img, int offset_x, int offset_y) {
	if (tiro->state == 1) {
		if(tiro_img != NULL) {
            // Desenha a imagem
            al_draw_bitmap(tiro_img, tiro->x + offset_x, tiro->y + offset_y, 0);
		}
	}
}
void colisao_tiro_aliens(Tiro *tiro, Alien aliens[E_LINHAS][E_COLUNAS], int* p_score) {
	for (int l = 0; l < E_LINHAS; l++) {
		for (int c = 0; c < E_COLUNAS; c++) {
			if (aliens[l][c].state != 0 && tiro->state != 0 &&
				tiro->x >= aliens[l][c].x && tiro->x <= aliens[l][c].x + ALIEN_W && 
				tiro->y <= aliens[l][c].y && tiro->y >= aliens[l][c].y - ALIEN_H) {
					aliens[l][c].state = 0;
					tiro->state = 0;
					(*p_score)++;
					return;
			}
		}
	}
}
//----------------------------//

//-------Funções Recorde------//
int compara_score_recorde(int score, int *record) {
	//abre arquivo como read
	FILE *file = fopen("recorde.txt", "r");

	if(file != NULL) {
		//scanea qual o último recorde e o armazena no endereço de memória apontado por recorde
		fscanf(file, "%d", record);
		fclose(file);
	}
	//se o score atual for maior que o último recorde
	if(*record < score ) {
		//abre o arquivo no modo write (apaga o último)
		file = fopen("recorde.txt", "w");
		fprintf(file, "%d", score);
		fclose(file);
		return 1;
	}
	return 0;
}
//----------------------------//

//----------Cenários----------//
void draw_scenario(ALLEGRO_BITMAP* current_bg, int offset_x, int offset_y) {
    // Preenche toda a janela com branco (incluindo bordas)
    al_clear_to_color(al_map_rgb(240, 240, 255));

    // Desenha o cenário do jogo (centralizado)
    if (current_bg != NULL) {
        al_draw_bitmap(current_bg, offset_x, offset_y, 0);
    }

    // Grama (renderizada dentro da área do jogo)
    al_draw_filled_rectangle(
        offset_x,
        offset_y + (SCREEN_H - GRASS_H),
        offset_x + SCREEN_W,
        offset_y + SCREEN_H,
        al_map_rgb(40, 175, 0)
    );
}
//----------------------------//

//--------Função Menu---------//
int mostrar_menu(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *menu_font) {

    int resolucao = 1;     // 0 = 960x540, 1 = 1280x720
    int dificuldade = 1;   // 0 = fácil, 1 = médio, 2 = difícil
    int selecionando = 3;  // 2 = resolucao, 1 = dificuldade

    ALLEGRO_EVENT ev;

    while (selecionando != 0) {
		//Seleção da resolução do jogo
        while (selecionando == 3) {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            al_draw_text(menu_font, al_map_rgb(255,255,255), 100, 100, 0, "Escolha a resolucao:");
            al_draw_text(menu_font, al_map_rgb(255,255,255), 120, 140, 0, resolucao == 0 ? "-> 960 x 540" : "   960 x 540");
            al_draw_text(menu_font, al_map_rgb(255,255,255), 120, 180, 0, resolucao == 1 ? "-> 1280 x 720" : "   1280 x 720");
			al_draw_text(menu_font, al_map_rgb(200,200,0), 100, 420, 0, "Pressione W ou S para navegar");
            al_draw_text(menu_font, al_map_rgb(200,200,0), 100, 460, 0, "Pressione ENTER para selecionar a resolucao");
			al_draw_text(menu_font, al_map_rgb(150,150,150), 100, 500, 0, "Pressione ESC para sair");

            al_flip_display();
            al_wait_for_event(event_queue, &ev);

            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_W:
                    case ALLEGRO_KEY_S:
                        resolucao = 1 - resolucao;
                        break;

                    case ALLEGRO_KEY_ENTER:
                        selecionando = 2;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        return 0;
                }
            }
        }

        //Seleção da dificuldade do jogo
        while (selecionando == 2) {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            al_draw_text(menu_font, al_map_rgb(255,255,255), 100, 240, 0, "Escolha a dificuldade:");
            al_draw_text(menu_font, al_map_rgb(255,255,255), 120, 280, 0, dificuldade == 0 ? "-> Facil" : "   Facil");
            al_draw_text(menu_font, al_map_rgb(255,255,255), 120, 320, 0, dificuldade == 1 ? "-> Medio" : "   Medio");
            al_draw_text(menu_font, al_map_rgb(255,255,255), 120, 360, 0, dificuldade == 2 ? "-> Dificil" : "   Dificil");
			al_draw_text(menu_font, al_map_rgb(200,200,0), 100, 420, 0, "Pressione W ou S para navegar");
            al_draw_text(menu_font, al_map_rgb(200,200,0), 100, 460, 0, "Pressione ENTER para selecionar a dificuldade");
			al_draw_text(menu_font, al_map_rgb(150,150,150), 100, 500, 0, "Pressione ESC para sair");

            al_flip_display();
            al_wait_for_event(event_queue, &ev);

            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_W:
                        if (dificuldade > 0) dificuldade--;
                        break;

                    case ALLEGRO_KEY_S:
                        if (dificuldade < 2) dificuldade++;
                        break;

                    case ALLEGRO_KEY_ENTER:
                        selecionando = 1;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        return 0;
                }
            }
        }
		while (selecionando == 1) {
			//Início do jogo
			al_clear_to_color(al_map_rgb(0, 0, 0));

			ALLEGRO_BITMAP *alien_menu = al_load_bitmap("sprites/alien_menu.png");
			al_draw_bitmap(alien_menu, WINDOW_W/2 - 250, WINDOW_H/2 - 340, 0);

			ALLEGRO_BITMAP *nave_menu = al_load_bitmap("sprites/nave_menu.png");
			al_draw_bitmap(nave_menu, WINDOW_W/2 - 300, WINDOW_H/2 - 10, 0);


            al_draw_text(menu_font, al_map_rgb(200,200,0), 100, 670, 0, "Pressione ENTER para iniciar");
			al_draw_text(menu_font, al_map_rgb(150,150,150), 100, 690, 0, "Pressione ESC para sair");

			
            al_flip_display();
            al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_ENTER:
						al_destroy_bitmap(nave_menu);
						al_destroy_bitmap(alien_menu);
						selecionando = 0;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        return 0;
                }
            }
		}
    }

    //Aplica as configurações:
    if (resolucao == 0) {
        SCREEN_W = 960;
        SCREEN_H = 540;

		switch (dificuldade) {
			case 0: E_LINHAS = 4; E_COLUNAS = 5; ALIEN_X_VEL = 2.0; break;
			case 1: E_LINHAS = 4; E_COLUNAS = 7; ALIEN_X_VEL = 2.5; break;
			case 2: E_LINHAS = 6; E_COLUNAS = 8; ALIEN_X_VEL = 3.0; NAVE_VEL = 6; break;
    	}
    } else {
        SCREEN_W = 1280;
        SCREEN_H = 720;

    	switch (dificuldade) {
			case 0: E_LINHAS = 5; E_COLUNAS = 8; ALIEN_X_VEL = 3.0; break;
			case 1: E_LINHAS = 6; E_COLUNAS = 9; ALIEN_X_VEL = 3.2; break;
			case 2: E_LINHAS = 6; E_COLUNAS = 11; ALIEN_X_VEL = 3.4; break;
    	}
    }
    return 1;
}
//----------------------------//

int main () {
	srand(time(NULL));

//------------------------Roteiro de Inicializações------------------------//
    ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
    //inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	//inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	
	if (!al_install_audio()) {
		fprintf(stderr, "Falha ao inicializar o áudio!\n");
		return -1;
	}
	if (!al_init_acodec_addon()) {
		fprintf(stderr, "Falha ao inicializar o codec de áudio!\n");
		return -1;
	}
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}
	//cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
	display = al_create_display(WINDOW_W, WINDOW_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}
	//instala o mouse
	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}	
//-------------------------------------------------------------------------//

//----Inicializações Gerais---//
	al_init_image_addon();
	al_init_font_addon();
    al_init_ttf_addon();
//----------------------------//

//---------------------------Registro de Eventos---------------------------//
	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registra na fila os eventos de mouse (ex: clicar em um botao do mouse)
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//-------------------------------------------------------------------------//

//--------------------------Inicialização do Menu--------------------------//
	ALLEGRO_FONT *menu_font = al_load_font("add-ons/pcsenior.ttf", 20, 0);
	ALLEGRO_BITMAP* menu_tipos_aliens[6];
			const char* menu_alien_files[6] = {"sprites/alien1.png", "sprites/alien2.png", "sprites/alien3.png", "sprites/alien4.png", "sprites/alien5.png", "sprites/alien6.png"};

			for(int i = 0; i < 6; i++) {
        		menu_tipos_aliens[i] = al_load_bitmap(menu_alien_files[i]);
    		}

	int continuar = mostrar_menu(event_queue, menu_font);
	if (!continuar) {
    	al_destroy_event_queue(event_queue);
    	al_destroy_display(display);
    	return 0;
	}
		
	//Centraliza a tela do jogo caso se escolha a tela pequena
	int offset_x = (WINDOW_W - SCREEN_W) / 2;
	int offset_y = (WINDOW_H - SCREEN_H) / 2; 
//-------------------------------------------------------------------------//

	al_flip_display();

//--------------------Criação das Estruturas Principais--------------------//
	Nave nave;
	initNave(&nave);
	
	Alien alien;
	initAlien(&alien);

	Alien aliens[E_LINHAS][E_COLUNAS];
	initAliens(&alien, aliens);

	Tiro tiro;
	initTiro(&tiro, &nave);
//-------------------------------------------------------------------------//

//-------------------Inicialização das Imagens do Cenário------------------//
	ALLEGRO_BITMAP *tiro_img = NULL;
	ALLEGRO_BITMAP *nave_img = NULL;
	const char* bg_files[4] = {"sprites/bg1.png", "sprites/bg2.png", "sprites/bg3.png", "sprites/bg4.png"};
	const char* gbg_files[4] = {"sprites/gbg1.png", "sprites/gbg2.png", "sprites/gbg3.png", "sprites/gbg4.png"};

    ALLEGRO_BITMAP* backgrounds[4];
	if (SCREEN_H == 540) {
		for(int i = 0; i < 4; i++) {
			backgrounds[i] = al_load_bitmap(bg_files[i]);
		}
	}
	else if (SCREEN_H == 720) {
		for(int i = 0; i < 4; i++) {
			backgrounds[i] = al_load_bitmap(gbg_files[i]);
		}
	}
	ALLEGRO_BITMAP* current_bg = backgrounds[rand() % 4];

	tiro_img = al_load_bitmap("sprites/TIRO_SMALL.png");
	nave_img = al_load_bitmap("sprites/NAVE_SMALL.png");
//-------------------------------------------------------------------------//

//-------------------Inicialização das Imagens dos Aliens------------------//
	ALLEGRO_BITMAP* tipos_aliens[6];
	const char* alien_files[6] = {"sprites/alien1.png", "sprites/alien2.png", "sprites/alien3.png", "sprites/alien4.png", "sprites/alien5.png", "sprites/alien6.png"};

	for(int i = 0; i < 6; i++) {
        tipos_aliens[i] = al_load_bitmap(alien_files[i]);
    }
//-------------------------------------------------------------------------//

//---------------------Inicialização de Escritas/Fontes--------------------//
	char game_won[] = "Congratulations, you won!";
	char game_lost[] = "Game over!";

	char pontuacao_text[20];
	int score = 0;
	int* p_score = &score;
	
    ALLEGRO_FONT *game_font = al_load_font("add-ons/pcsenior.ttf", 32, 1);
//-------------------------------------------------------------------------//

//----------------------Inicialização de Sons/Samples----------------------//
	al_reserve_samples(16);
	ALLEGRO_SAMPLE *tiro_sound = al_load_sample("add-ons/tiro_sound.wav");
	ALLEGRO_SAMPLE *alien_sound = al_load_sample("add-ons/alien_sound.wav");
	ALLEGRO_SAMPLE *musica = al_load_sample("add-ons/music.wav");
	ALLEGRO_SAMPLE *game_over = al_load_sample("add-ons/game_over_sound.wav");
	ALLEGRO_SAMPLE *you_win_sound = al_load_sample("add-ons/you_win_sound.wav");

//-------------------------------------------------------------------------//

	//inicia o temporizador
	al_start_timer(timer);
	al_play_sample(musica, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	int playing = 1;
	while (playing) {
		
		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		if(ev.type == ALLEGRO_EVENT_TIMER) {

			update_nave(&nave);
			update_aliens(aliens, &alien, alien_sound);
			update_tiro(&tiro);
			colisao_tiro_aliens(&tiro, aliens, p_score);

			draw_scenario(current_bg, offset_x, offset_y);
			draw_nave(nave, nave_img, offset_x, offset_y);
			draw_aliens(aliens, tipos_aliens, offset_x, offset_y);
			draw_tiro(&tiro, &nave, tiro_img, offset_x, offset_y);

			sprintf(pontuacao_text, "Score: %d", score);
			al_draw_text(game_font, al_map_rgb(255, 255, 255), 10 + offset_x, SCREEN_H + offset_y - (GRASS_H * 0.8), 0, pontuacao_text);
			
			//atualiza a tela (quando houver algo para mostrar)
			al_flip_display();
			
			//-Possibilidades Jogo Acabar-//
			if (colisao_aliens_solo(aliens) || colisao_aliens_nave(&nave, aliens) || verifica_state_aliens(aliens)) {
				al_stop_samples();
				if (colisao_aliens_solo(aliens)) {
					al_draw_text(game_font, al_map_rgb(255, 0, 0), (SCREEN_W + offset_x)/3, (SCREEN_H + offset_y)/2, 0, game_lost);
					al_play_sample(game_over, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
					al_rest(2);
				}
				else if (colisao_aliens_nave(&nave, aliens)) {
					al_draw_text(game_font, al_map_rgb(255, 0, 0), (SCREEN_W + offset_x)/3, (SCREEN_H + offset_y)/2, 0, game_lost);
					al_play_sample(game_over, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
					al_rest(2);
				}
				else if (verifica_state_aliens(aliens)) {
					al_draw_text(game_font, al_map_rgb(0, 255, 0), (SCREEN_W + offset_x)/6, (SCREEN_H + offset_y)/2, 0, game_won);
					al_play_sample(you_win_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
					al_rest(2);
				}
    			playing = 0;
			}
			//----------------------------//
			al_flip_display();

		}

		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
			exit(0);
		}
		
		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {

				case ALLEGRO_KEY_A:
					nave.esq = 1;
					break;

				case ALLEGRO_KEY_D:
					nave.dir = 1;
					break;
				case ALLEGRO_KEY_SPACE:
					dispara_tiro(&tiro, &nave, tiro_sound);
					break;
			}
		}

		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch(ev.keyboard.keycode) {

				case ALLEGRO_KEY_A:
					nave.esq = 0;
					break;

				case ALLEGRO_KEY_D:
					nave.dir = 0;
					break;
			}
		}
	}
	al_rest(1);

	int record;
	char sscore[20];
	al_clear_to_color(al_map_rgb(230,240,250));

	sprintf(sscore, "Score: %d", score);
	al_draw_text(game_font, al_map_rgb(200, 0, 30), (SCREEN_W + offset_x)/3, (SCREEN_H + offset_y)/3, 0, sscore);

	if (compara_score_recorde(score, &record)) {
		al_draw_text(game_font, al_map_rgb(200, 20, 30), SCREEN_W/3, 100+SCREEN_H/3, 0, "NEW RECORD!");
	}
	else {
		sprintf(sscore, "Record: %d", record);
		al_draw_text(game_font, al_map_rgb(0, 200, 30), SCREEN_W/3, 100+SCREEN_H/3, 0, sscore);
	}
	//reinicializa a tela
	al_flip_display();	
	al_rest(3);	


	al_destroy_sample(tiro_sound);
	al_destroy_sample(alien_sound);
	al_destroy_sample(musica);
	al_uninstall_audio();
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

    return 0;
}