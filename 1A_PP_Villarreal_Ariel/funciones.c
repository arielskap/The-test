#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <conio.h>
#include <ctype.h>
void inicializarvector(eDuenio duenio[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(duenio[i].estado==0)
        {
            duenio[i].estado=0;
        }
    }
}
void inicializarvectorAutomovil(eAutomovil automovil[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(automovil[i].estado==0)
        {
            automovil[i].estado=0;
        }
    }
}
int buscarLibre(eDuenio duenio[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(duenio[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarLibreAutomovil(eAutomovil automovil[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(automovil[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarId(int id, eDuenio duenio[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(duenio[i].idDuenio==id&&duenio[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarPatente(char patente[], eAutomovil automovil[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(strcmp(automovil[i].patente,patente)==0 && automovil[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void altaDuenio(eDuenio duenio[],int tam)
{
    int lugar;
    int esta;
    int id;
    lugar=buscarLibre(duenio,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d",&id);
        esta=buscarId(id,duenio,tam);
        if(esta!=-1)
        {
            printf("\nEl ID: %d ya se encuentra registrado en el sistema. \n",id);
        }
        else
        {
            duenio[lugar].idDuenio=id;
            printf("\nIngrese nombre y apellido: ");
            fflush(stdin);
            gets(duenio[lugar].nombreyapellido);
            printf("\nIngrese Direccion: ");
            fflush(stdin);
            gets(duenio[lugar].direccion);
            printf("\nIngrese numero de Tarjeta: ");
            scanf("%d",&duenio[lugar].numTarjeta);
            duenio[lugar].estado=1;
            printf("\nDuenio Agregado con exito!\n");
        }
    }
}
void altaAutomovil(eAutomovil automovil[],int tamA,eDuenio duenio[],int tamD)
{
    int lugar;
    int marca;
    int esta;
    int id;
    int flag;
    int estaPatente;
    lugar=buscarLibreAutomovil(automovil,tamA);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese ID del Cliente que Estaciona: ");
        scanf("%d",&id);
        esta=buscarId(id,duenio,tamD);
        if(esta==-1)
        {
            printf("\nNo existe el cliente\n");
        }
        else
        {
            printf("Ingrese Patente: ");
            fflush(stdin);
            gets(automovil[lugar].patente);
            estaPatente=buscarPatente(automovil[lugar].patente,automovil,tamA);
            if(estaPatente==-1)
            {
                printf("\n1-ALPHA_ROMEO\n2-FERRARI\n3-AUDI\n4-OTRO\n\nIngrese Opcion de Marca: ");
                scanf("%d",&marca);
                if(marca==1 || marca==2 || marca==3 || marca==4)
                {
                    if(marca==1)
                    {
                        strcpy(automovil[lugar].descripcion,"ALPHA_ROMEO");
                    }
                    if(marca==2)
                    {
                        strcpy(automovil[lugar].descripcion,"FERRARI");
                    }
                    if(marca==3)
                    {
                        strcpy(automovil[lugar].descripcion,"AUDI");
                    }
                    if(marca==4)
                    {
                        strcpy(automovil[lugar].descripcion,"OTRO");
                    }
                    automovil[lugar].marca=marca;
                    printf("\nIngrese horario de entrada del automovil: ");
                    scanf("%d",&automovil[lugar].horario);
                    do
                    {
                        if(automovil[lugar].horario>0 && automovil[lugar].horario<24)
                        {
                            automovil[lugar].estado=1;
                            automovil[lugar].idDuenio=duenio[esta].idDuenio;
                            printf("\nAutomovil agregado con exito!\n\n");
                            flag=1;
                        }
                        else
                        {
                            printf("Horario INCORRECTO\n\nReingrese horario: ");
                            scanf("%d",&automovil[lugar].horario);
                            flag=0;
                        }
                    }
                    while(flag==0);
                }
                else
                {
                    printf("OPCION INVALIDA!!\n\n");
                }
            }
            else
            {
                printf("\nEse Vehiculo ya se encuentra estacionado!!\n");
            }
        }
    }
}
void modificacionTarjeta(eDuenio duenio[],int tam)
{
    int id;
    int indice;
    char confirma;
    printf("\nIngrese ID a modificar: ");
    scanf("%d",&id);
    indice=buscarId(id,duenio,tam);
    if(indice!=-1)
    {
        printf("\nId: %d----Nombre y Apellido: %s----Numero de Tarjeta: %d\n",duenio[indice].idDuenio,duenio[indice].nombreyapellido,duenio[indice].numTarjeta);
        printf("\nEsta seguro que desea modificar el numero de Tarjeta? s/n: ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            printf("\nIngrse nueva Tarjeta: ");
            scanf("%d",&duenio[indice].numTarjeta);
            printf("\nTarjeta modificada con exito!\n");
        }
        else
        {
            printf("\naccion cancelada.\n");
        }
    }
    else
    {
        printf("\nID no encontrada.\n");
    }
}
void organizarpersonas(eAutomovil automovil[],int tamA,eDuenio duenio[],int tamD)
{
    int i, j;
    eDuenio auxDuenio;
    eAutomovil auxAutomovil;
    int flag=0;
    for(i=0; i<tamA-1; i++)
    {
        for(j=i+1; j<tamA; j++)
        {
            if(automovil[i].estado==1 && automovil[j].estado==1)
            {
                if(automovil[i].horario>automovil[j].horario)
                {
                    auxAutomovil=automovil[j];
                    automovil[j]=automovil[i];
                    automovil[i]=auxAutomovil;

                    auxDuenio=duenio[j];
                    duenio[j]=duenio[i];
                    duenio[i]=auxDuenio;
                }
                else
                {
                    if(automovil[i].horario==automovil[j].horario)
                    {
                        if(strcmp(automovil[i].patente,automovil[j].patente)>0)
                        {
                            auxAutomovil=automovil[j];
                            automovil[j]=automovil[i];
                            automovil[i]=auxAutomovil;

                            auxDuenio=duenio[j];
                            duenio[j]=duenio[i];
                            duenio[i]=auxDuenio;
                        }
                    }
                }
            }
        }
    }
    printf("\nDatos de los Duenios registrados:\n\n");
    for(i=0; i<tamD; i++)
    {
        if(duenio[i].estado!=0)
        {
            for(int j=0; j<tamA; j++)
            {
                if(automovil[j].estado!=0 && automovil[j].idDuenio==duenio[i].idDuenio)
                {
                    printf("Auto: %s---Patente: %s---Hora de entrada: %dhs\n",automovil[j].descripcion,automovil[j].patente,automovil[j].horario);
                    flag=1;
                }
            }
            if(flag==1)
            {
                printf("ID: %d----Nombre y apellido: %s\n\n",duenio[i].idDuenio,duenio[i].nombreyapellido);
                flag=0;
            }
        }
    }
}
void propietariosAudi(eDuenio duenio[],int tamD,eAutomovil automovil[],int tamA)
{
    printf("\nPROPIETARIOS AUDI!\n\n");
    for(int i=0; i<tamA; i++)
    {
        if(automovil[i].marca==3 && automovil[i].estado==1)
        {
            for(int j=0; j<tamD; j++)
            {
                if(automovil[i].idDuenio==duenio[j].idDuenio)
                {
                    printf("%s\n",duenio[j].nombreyapellido);
                }
            }
        }
    }
}
int bajaAutomovil(eAutomovil automovil[], int tamA,eDuenio duenio[],int tamD,int recaudacionxMarca[])
{
    int id;
    int indice;
    char patente[20];
    int patenteindice;
    int horariofinal;
    int horariototal;
    int valorestadia=0;
    printf("\nIngrese el ID del Cliente que se retira: ");
    scanf("%d",&id);
    indice=buscarId(id,duenio,tamD);
    if(indice!=-1)
    {
        printf("\nIngrese Patente: ");
        fflush(stdin);
        gets(patente);
        patenteindice=buscarPatente(patente,automovil,tamA);
        if(patenteindice!=-1)
        {
            if(duenio[indice].idDuenio==automovil[patenteindice].idDuenio)
            {
                printf("\nTiempo final estacionado: ");
                scanf("%d",&horariofinal);
                if(horariofinal>0 && horariofinal <=24 && horariofinal>automovil[patenteindice].horario)
                {
                    horariototal=horariofinal-automovil[patenteindice].horario;
                    if(automovil[patenteindice].marca==1)
                    {
                        valorestadia=horariototal*150;
                        recaudacionxMarca[0]=valorestadia;
                    }
                    if(automovil[patenteindice].marca==2)
                    {
                        valorestadia=horariototal*175;
                        recaudacionxMarca[1]=valorestadia;
                    }
                    if(automovil[patenteindice].marca==3)
                    {
                        valorestadia=horariototal*200;
                        recaudacionxMarca[2]=valorestadia;
                    }
                    if(automovil[patenteindice].marca==4)
                    {
                        valorestadia=horariototal*250;
                        recaudacionxMarca[3]=valorestadia;
                    }
                    printf("\nNombre: %s\nPatente: %s\nMarca: %s\nValor de estadio por %dhs: $$%d\n",duenio[indice].nombreyapellido,automovil[patenteindice].patente,automovil[patenteindice].descripcion,horariototal,valorestadia);
                    automovil[patenteindice].estado=0;
                }
                else
                {
                    printf("\nHorario imposible!\n");
                }

            }
            else
            {
                printf("\nEl vehiculo le pertenece a otro Duenio!\n");
            }

        }
        else
        {
            printf("\nPatente no encontrada!!\n");
        }
    }
    else
    {
        printf("\nID no encontrada.\n");
    }
    return valorestadia;
}
