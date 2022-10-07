#include <stdio.h>
#include <math.h>
#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

// int test[3] = {GL_LINES, GL_POINT, 0};
node_coordinates *pointsList = NULL;
int colorSelector = 0;
int modeToDraw = 0;
int strokeSize = 1;
int typeOfSelector = 0;

void drawDot()
{
}

void keyboard_callback(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'b':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para retangulo a partir dos pontos da diagonal");
            modeToDraw = 2;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case 'B':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para retangulo a partir dos pontos da diagonal");
            modeToDraw = 2;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case 'l':
        printf("\n ///////////as coordenadas que definem as figuras seram limpadas///////////////");
        interate_over_list(remove_node_of_list_end, pointsList);
        printf("\n\n///////////PONTOS ATUAIS DA LISTA/////////////");
        interate_over_list(print_node_values, pointsList);
        printf("\n\n//////////////////////////////////////////////");
        break;
    case 'L':
        interate_over_list(remove_node_of_list_end, pointsList);
        break;
    case 'e':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n////////////MODO DE EDICAO DE COR: use as teclas de 0-9 para selecionar cor///////////");
            typeOfSelector = 0;
        }
        else
        {
            printf("\n/////////insira mais um ponto para terminar de definir a figura! depois troque o modo de edicao//////");
        }

        break;
    case 'E':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n////////////MODO DE EDICAO DE COR: use as teclas de 0-9 para selecionar cor///////////");
            typeOfSelector = 0;
        }
        else
        {
            printf("\n/////////insira mais um ponto para terminar de definir a figura! depois troque o modo de edicao//////");
        }
        break;
    case 'k':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n////////////MODO DE EDICAO DE TRACO: use as teclas de 0-9 mudar o tamanho do traco///////////");
            typeOfSelector = 1;
        }
        else
        {
            printf("\n/////////insira mais um ponto para terminar de definir a figura! depois troque o modo de edicao//////");
        }
        break;
    case 'K':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n////////////MODO DE EDICAO DE COR: use as teclas de 0-9 para selecionar cor///////////");
            typeOfSelector = 1;
        }
        else
        {
            printf("\n/////////insira mais um ponto para terminar de definir a figura! depois troque o modo de edicao//////");
        }

        break;
    case 'r':
        // must draw lines
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para reta");
            modeToDraw = 0;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case 'c':
        // must draw Circles
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para circunferencia");

            modeToDraw = 1;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case 'R':
        // must draw lines
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para reta");
            modeToDraw = 0;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case 'C':
        if (calculate_list_size(pointsList) % 2 == 0)
        {
            printf("\n\n///////////////////////////");
            printf("\n!@# modo trocado para circunferencia");
            modeToDraw = 1;
        }
        else
            printf("\n !@# insira outro ponto para completar o par ordenado antes de trocar de modo \n");
        break;
    case '1':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");
            strokeSize = 1;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 1;
        }

        break;
    case '2':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 2;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 2;
        }
        break;
    case '3':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 3;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 3;
        }
        /* code */
        break;
    case '4':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 4;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 4;
        }
        /* code */
        break;
    case '5':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 5;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 5;
        }
        /* code */
        break;
    case '6':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 6;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 6;
        } /* code */
        break;
    case '7':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 7;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 7;
        }
        /* code */
        break;
    case '8':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 8;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 8;
        }
        /* code */
        break;
    case '9':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 9;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 9;
        }
        /* code */
        break;
    case '0':
        if (typeOfSelector)
        {
            printf("\n//////////VOCE SELECIONOU UM NOVO TAMANHO DE TRACO");

            strokeSize = 10;
        }
        else
        {
            printf("\n//////////VOCE SELECIONOU UMA NOVA COR");
            colorSelector = 0;
        }
        /* code */
    default:
        break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            add_node_to_list_end(&pointsList, x, y, modeToDraw, strokeSize, colorSelector);
            printf("\n\n///////////PONTOS ATUAIS DA LISTA/////////////");
            interate_over_list(print_node_values, pointsList);
            printf("\n\n//////////////////////////////////////////////");
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    ///////////////////
    // research
    // this basicly does the scale transformation
    // through the view port and window
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0, w, h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES);
    iterate_over_list_repass_every_two_points(draw_on_two_points, pointsList);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("primitives");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard_callback);
    glutMouseFunc(mouse);
    glutMainLoop();

    /* code */
    return 0;
}
