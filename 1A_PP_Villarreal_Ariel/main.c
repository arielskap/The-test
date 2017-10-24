#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMD 40
#define TAMA 20
int main()
{
    int opcion;
    int flag=1;
    int dinero;
    int dinerototal=0;
    int recaudacionxMarca[]={0,0,0,0};
    eDuenio duenio[TAMD]={{23,"Ariel Villarreal","Calle falsa 123",4155,1},{2,"Jorge Alvarez","Garay 233",4143,1},{3,"Candela Sicono","Juan 3425",1234,1}};
    eAutomovil automovil[TAMA]={{"abc 123",3,15,1,"AUDI",23},{"ror 523",2,17,1,"FERRARI",2},{"jaj 564",4,13,1,"OTROS",3}};
    inicializarvector(duenio,TAMD);
    inicializarvectorAutomovil(automovil,TAMA);
    do
    {
        system("cls");
        printf("Opciones:\n\n");
        printf("1.Alta de Duenio.\n");
        printf("2.Modificacion de Tarjeta.\n");
        printf("3.Alta de Automovil.\n");
        printf("4.Baja de Automovil.\n");
        printf("5.INFORMAR\n");
        printf("6.Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("ALTA DUENIO\n\n");
            altaDuenio(duenio,TAMD);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("MODIFICACION TARJETA\n\n");
            modificacionTarjeta(duenio,TAMD);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("ALTA AUTOMOVIL\n\n");
            altaAutomovil(automovil,TAMA,duenio,TAMD);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("BAJA AUTOMOVIL\n\n");
            dinero=bajaAutomovil(automovil,TAMA,duenio,TAMD,recaudacionxMarca);
            dinerototal+=dinero;
            system("pause");
            break;
        case 5:
            system("cls");
            printf("INFORMAR\n\n");
            organizarpersonas(automovil,TAMA,duenio,TAMD);
            system("pause");
            propietariosAudi(duenio,TAMD,automovil,TAMA);
            system("pause");
            printf("\nRECAUDACION TOTAL POR MARCA\n\n");
            printf("ALPHA_ROMEO: $%d\nFERRARI: $%d\nAUDI: $%d\nOTROS: $%d\n",recaudacionxMarca[0],recaudacionxMarca[1],recaudacionxMarca[2],recaudacionxMarca[3]);
            system("pause");
            printf("\n\nRECAUDACION TOTAL: $%d\n",dinerototal);
            system("pause");
            break;
        case 6:
            printf("Chau!!");
            flag=0;
            break;
        default:
            printf("Opcion Invalida!!\n");
            system("pause");
        }
    }while(flag==1);
    return 0;
}
