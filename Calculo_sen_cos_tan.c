// Autor: Levi Prudêncio Araújo Neto

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979324
float prt_ang, prt_ang_1;

//Função do cálculo do Fatorial
float Fatorial(float x){
    float i, j = 1;
    for(i = 1;  i <= x; i++){
        j = i * j;
    }
    if (x == 0){
        j =  0;
    }
      return j;
}

//Função converter em Radianos
float Convert_radiano(float graus){
    float  rad, G = graus;                // Declaração variáveis locais
           rad    = G * (PI / 180);     // Operação de conversão
    return rad;                       // retorna o valor da conversão
}


//Função cálculo do seno
float Func_seno(float ang){
    float i, rad, x, acum, F, sinal;
    prt_ang = ang;                        // atribui o valor do ângulo a uma variável global
        rad = Convert_radiano(ang);     // Chama a função de conversão(graus para radiano),que retorna um valor tipo float para variável rad
          x = rad;
       acum = x;
      sinal = 1;                  //    \\ variávek sinal recebe valor 1
    // Operação do cálculo do seno do  ângulo
    for (i = 3; i <= 33  ; i = i + 2){// \\Somatorio de operações
        if(sinal  ==  1){           //    \\ se variável sinal for 1 a operação ira subtrair da variável acumalador

             acum = acum - ((pow(x , i))/ (F = Fatorial(i)));
            sinal =   0;
        }else{                       //      \\ se variável sinal for 0 a operação ira somar a variável acumalador
             acum = acum + ((pow(x, i)) / (F = Fatorial(i)));
            sinal =   1;                      // A variável sinal vária a cada incremento do "FOR", ou seja a cada incremento uma operação diferente ira ocorrer
        }
    }
return acum;
}

//Função cálculo Do cosseno
float Func_cosseno(float ang){
    float i, rad, x, acum, F, sinal;
    prt_ang_1 = ang;                    // atribui o valor do ângulo a uma variável global
    rad = Convert_radiano(ang);       // Chama a função de conversão(graus para radiano),que retorna um valor tipo float para variável rad
    x = rad;
    acum = x ;
    sinal = 1;
    // Operação do cálculo do cosseno do  ângulo
    for (i = 2 ; i <= 34; i = i + 2)// Somatorio de operações
    {
        if (sinal == 1)          //    \\ se variável sinal for 1 a operação ira subtrair da variável acumalador
        {
            if(i==2){
                acum = 1 - ((pow(x, i)) / (F = Fatorial(i)));   //      \\if atende a um caso especial do cálculo do cosseno
                sinal = 0;
            }else{
                acum = acum - ((pow(x, i)) / (F = Fatorial(i)));
                sinal = 0;
            }
        }
        else
        {
            acum = acum + ((pow(x, i)) / (F = Fatorial(i)));    //      \\ se variável sinal for 0 a operação ira somar a variável acumalador
            sinal = 1;                                 //       \\      // A variável sinal vária a cada incremento do "FOR", ou seja a cada incremento uma operação diferente ira ocorrer
        }
    }
    return acum;                                     //         || retorna o valor cálculado
}

int main(){
     float c, s, t,ang_s,ang_c,ang_t ;
     int opc, close = 1;

    printf("\t\t\t[Valores numericos dos angulos]");
    while(close == 1 ){  //          \\ Menu de escolha da função
        printf("\n[1]Calculo do seno\n[2]Calculo do cosseno\n[3]Calculo da tangente\nDigite a opcao:");
        scanf("%d",&opc);

        if(opc == 1) {              //Seleção da função de cálculo do seno
             printf("\nDigite o angulo do seno:");
             scanf("%f", &ang_s);
             s = Func_seno(ang_s);
             printf("\nO Valor do Seno(%.0f) = %.6lf", prt_ang,s);

        }else if(opc == 2){      //Seleção da função de cálculo do cosseno
             printf("\nDigite o angulo do cosseno:");
             scanf("%f", &ang_c);
             c = Func_cosseno(ang_c);
            printf("\nO Valor do Cosseno(%.0f) = %.6lf", prt_ang_1,c);

        }else if(opc == 3) {  //Seleção da função de cálculo da Tangente
             printf("\nDigite o angulo da tangente:");
             scanf("%f", &ang_t);
              if(ang_t >=90){
                 int  i;
                 float x = 90;
                for(i = 1; i <= ang_t; i = i + 2){
                    x = x *i;
                    if(x == ang_t){
                        printf("\nErro entrada invalida para a tangente!!!");
                        continue;
                    }
                }
             }
              s = Func_seno(ang_t);
              c = Func_cosseno(ang_t);
              t = (s / c);
              printf("\nO Valor da Tangente(%.2f) = %.6lf",ang_t,t);
        }
        printf("\n\nDeseja continuar 1 ou 0 para encerrar:");
        scanf("%d",&close);
        if(close != 1) break;
    }

    system("pause>>NULL");

    //return 0;
}
