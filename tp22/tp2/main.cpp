#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct Incidente
{

    int codigoIncidente;
    char fechaHora[14];
    char dniAsegurado[11];
    char dniOtro[11];
    int nroPolisa;
    char calle[25];
    int altura;
};
struct PolisaAsegurado
{
    int nroPoliza;
    char dni[11];
    char nombre[10];
    char apellido[10];
    bool cuotaAlDia;
    char patente[9];
    int cantIncidentes;
    bool activa;
};
struct NodoPoliza
{
    int cant2020;
    PolisaAsegurado poliza;
    NodoPoliza *sig;
};

NodoPoliza *obtenerUltimoNodo(NodoPoliza *lista)
{

    if(lista)
    {
        while(lista->sig!=NULL)
        {
            lista=lista->sig;
        }
    }
    return lista;
}

void cargarAlFinal(NodoPoliza *&lista, PolisaAsegurado polizaACargar)
{
    NodoPoliza *nuevo=new NodoPoliza();
    NodoPoliza *ultimo=NULL;
    nuevo->poliza=polizaACargar;
    nuevo->sig= NULL;
    if(lista!=NULL)
    {
        ultimo=obtenerUltimoNodo(lista);
        ultimo->sig=nuevo;
    }
    else
    {
        lista=nuevo;
    }
    return;
}

int longLista(NodoPoliza *lista)
{
    int longitud=0;
    while(lista)
    {
        longitud++;
        lista=lista->sig;
    }
    return longitud;
}
//archivo de asegurados creada para probar el funcionamiento del programa

void aseguradosBakPrueba()
{
    FILE *f=fopen("Asegurados.Bak","wb");
    PolisaAsegurado poliza;

    strcpy(poliza.nombre,"walt ");
    strcpy(poliza.apellido,"disney");
    strcpy(poliza.patente,"iou213");
    strcpy(poliza.dni,"99.999.899");
    poliza.nroPoliza=123;
    poliza.activa=true;
    poliza.cantIncidentes=1;
    poliza.cuotaAlDia=true;


    fwrite(&poliza,sizeof(PolisaAsegurado),1,f);

    strcpy(poliza.nombre,"ronaldo ");
    strcpy(poliza.apellido,"tristaldo");
    strcpy(poliza.patente,"87i223");
    strcpy(poliza.dni,"99.999.888");
    poliza.nroPoliza=82;
    poliza.activa=true;
    poliza.cantIncidentes=3;
    poliza.cuotaAlDia=false;

    fwrite(&poliza,sizeof(PolisaAsegurado),1,f);

    strcpy(poliza.nombre,"andres");
    strcpy(poliza.apellido,"messirve");
    strcpy(poliza.patente,"3ld1e5z");
    strcpy(poliza.dni,"77.999.899");
    poliza.nroPoliza=10;
    poliza.activa=false;
    poliza.cantIncidentes=5;
    poliza.cuotaAlDia=true;

    fwrite(&poliza,sizeof(PolisaAsegurado),1,f);

    strcpy(poliza.nombre,"americo");
    strcpy(poliza.apellido,"vespuccio");
    strcpy(poliza.patente,"8723i2");
    strcpy(poliza.dni,"33.999.899");
    poliza.nroPoliza=133;
    poliza.activa=true;
    poliza.cantIncidentes=4;
    poliza.cuotaAlDia=true;

    fwrite(&poliza,sizeof(PolisaAsegurado),1,f);

    strcpy(poliza.nombre,"hernan");
    strcpy(poliza.apellido,"cortez");
    strcpy(poliza.patente,"3ld1e5z");
    strcpy(poliza.dni,"75.999.899");
    poliza.nroPoliza=14;
    poliza.activa=true;
    poliza.cantIncidentes=2;
    poliza.cuotaAlDia=true;

    fwrite(&poliza,sizeof(PolisaAsegurado),1,f);
    fclose(f);
    return;
}
//carga un archivo con incidentes que luego pueden ser procesados

void loteIncidentesPrueba(char nombre[])
{
    FILE *f=fopen(nombre,"wb");
    Incidente incidente;

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 2767;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.766.680");
    incidente.codigoIncidente=233;
    strcpy(incidente.dniOtro,"89.778.680");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 225;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=633;
    strcpy(incidente.dniOtro,"49.778.680");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 7776;
    strcpy(incidente.calle,"Carlos Calvo");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=167;
    strcpy(incidente.dniOtro,"59.778.680");
    incidente.nroPolisa=123;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 2678;
    strcpy(incidente.calle,"juramento");
    strcpy(incidente.dniAsegurado,"89.778.680");
    incidente.codigoIncidente=237;
    strcpy(incidente.dniOtro,"77.778.680");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2021050412:13");
    fwrite(&incidente,sizeof(Incidente),1,f);


    incidente.altura= 543;
    strcpy(incidente.calle,"Varela");
    strcpy(incidente.dniAsegurado,"85.542.230");
    incidente.codigoIncidente=35;
    strcpy(incidente.dniOtro,"89.111.765");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2020060109:55");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 543;
    strcpy(incidente.calle,"Varela");
    strcpy(incidente.dniAsegurado,"85.542.230");
    incidente.codigoIncidente=999;
    strcpy(incidente.dniOtro,"89.111.222");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2020070111:05");
    fwrite(&incidente,sizeof(Incidente),1,f);

    incidente.altura= 113;
    strcpy(incidente.calle,"Castro");
    strcpy(incidente.dniAsegurado,"76.232.230");
    incidente.codigoIncidente=89;
    strcpy(incidente.dniOtro,"89.999.765");
    incidente.nroPolisa=14;
    strcpy(incidente.fechaHora,"2020010106:55");
    fwrite(&incidente,sizeof(Incidente),1,f);
    fclose(f);
    return;
}
void mostrarPoliza(PolisaAsegurado poliza)
{
    cout<<"nombre:         "<< poliza.nombre<<endl;
    cout<<"apellido:       "<< poliza.apellido<<endl;
    cout<<"patente:        "<<poliza.patente <<endl;
    cout<<"dni:            "<<poliza.dni <<endl;
    cout<<"NroPoliza:      "<<poliza.nroPoliza <<endl;
    cout<<"activa?:        "<<poliza.activa <<endl;
    cout<<"cantIncidentes: "<<poliza.cantIncidentes <<endl;
    cout<<"cuotaAlDia?:    "<<poliza.cuotaAlDia <<endl;
    cout<<"============================"<<endl;
    return;
}

void mostrarListaPolizas(NodoPoliza *lista)
{
    while(lista)
    {
        mostrarPoliza(lista->poliza);
        lista=lista->sig;
    }
    return;
}
PolisaAsegurado leerPoliza()
{
    PolisaAsegurado poliza;

    cout<<"nroPoliza"<<endl;
    cin>>poliza.nroPoliza;
    cout<<"cantIncidentes"<<endl;
    cin>>poliza.cantIncidentes;
    cout<<"cuotasaldia"<<endl;
    cin>>poliza.cuotaAlDia;
    cout<<"nombre"<<endl;
    cin>>poliza.nombre;
    cout<<"dni"<<endl;
    cin>>poliza.dni;
    cout<<"patente"<<endl;
    cin>>poliza.patente;
    cout<<"apellido"<<endl;
    cin>>poliza.apellido;
    cout<<"activa"<<endl;
    cin>>poliza.activa;
    return poliza;
}

char mostrarMenu()
{
    cout<<"elegir una opcion del menu"<<endl;
    cout<<"1.levantar cuentas de Asegurados.Bak "<<endl;
    cout<<"2.Cargar una nueva póliza"<<endl;
    cout<<"3.Desactivar un poliza existente "<<endl;
    cout<<"4.Buscar una poliza por nroPoliza"<<endl;
    cout<<"5.Buscar poliza por dni"<<endl;
    cout<<"6.Listar todas las pólizas activas ordenadas por saldo descendente."<<endl;
    cout<<"7.Procesar un lote de incidentes."<<endl;
    cout<<"8.Mostrar todas las pólizas que tengan más de 5 incidentes durante todo el 2020"<<endl;
    cout<<"9. Mostrar el mismo reporte que el punto 7 en formato CSV."<<endl;
    cout<<"0. Finalizar jornada (sobreescribir “Asegurados.BAK” con polizas activas)."<<endl;
    cout<<"esc.Salir "<<endl;
    cout<<"==============================================="<<endl;
    char opcion;
    do
    {
        opcion=getch();
    }
    while ( (opcion!='0')&&(opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') &&(opcion!='6') && (opcion!='7')&&(opcion!='8')&&(opcion!='9')&& (opcion!=27));
    return opcion;
}
NodoPoliza *BuscarNodoAnterior(NodoPoliza *raiz, NodoPoliza* anterior_a)
{
    NodoPoliza *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sig!= anterior_a) )
        {
            p = p->sig;
        }
        return p;
    }
    else
        return NULL;
}
void borrarLista(NodoPoliza *&lista)
{
    NodoPoliza *anterior;
    NodoPoliza *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sig)
        {
            anterior = paux;
            paux= paux->sig;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sig=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

//ordena la lista de polizas activas descendentemente segun la cantIncidentes(se entiende que  cantIncidentes=saldo)
void ordenarListaDescen(NodoPoliza *&lista)
{
    int n,i,j;
    NodoPoliza *aux;
    NodoPoliza *anterior;
    NodoPoliza *proximo;
    bool inter;
    n= longLista(lista);
    for (i=0; i<=n-2; i++)
    {
        aux= lista;
        for (j=0; j<=n-2-i; j++)
        {
            if (   aux->poliza.cantIncidentes < aux->sig->poliza.cantIncidentes)
            {
                inter= true;
                if (aux==lista)
                {
                    lista= aux->sig;
                    proximo= lista->sig;
                    lista->sig=aux;
                    aux->sig=proximo;
                }
                else
                {
                    anterior=BuscarNodoAnterior(lista,aux);
                    proximo=aux->sig;
                    anterior->sig= proximo;
                    aux->sig= proximo->sig;
                    proximo->sig= aux;
                }
            }
            else
                inter=false;
            if (!inter)
            {
                aux= aux->sig;
            }
        }
    }
    return;
}

//con diagramas de lindsay
void escribirListaEnArchivo(NodoPoliza *&lista,char nom[])
{
    FILE *f=fopen(nom,"wb");
    PolisaAsegurado poliza;
    NodoPoliza *aux;
    if(f)
    {
        while(lista)
        {
            poliza=lista->poliza;
            fwrite(&poliza,sizeof(PolisaAsegurado),1,f);
            aux=lista->sig;
            delete lista;
            lista=aux;

        }
        fclose(f);
        cout<<"se escribio correctamente"<<endl;
    }
    else
    {
        cout<<"no se pudo abrir el archivo"<<endl;
    }
    return ;
}



void buscarPolizasActivas(NodoPoliza *lista,NodoPoliza *&listaPolizasAct)
{
    if(lista)
    {
        while(lista)
        {
            if(lista->poliza.activa)
            {
                cargarAlFinal(listaPolizasAct,lista->poliza);
            }

            lista=lista->sig;
        }
    }
    else
    {
        cout<<"lista vacia"<<endl;
    }
    return;
}

bool compararAnio(Incidente incidente)
{
    int anio_inci=(atoi(incidente.fechaHora))/1000000;
    if(2020==anio_inci)
    {
        return true;
    }
    else
    {
        return false;
    }

}

NodoPoliza *buscarXnroPoliza(NodoPoliza *lista, int nro)
{
    NodoPoliza *poliza;
    while(lista && (nro!=lista->poliza.nroPoliza))
    {
        lista=lista->sig;
    }
    return poliza=lista;
}

void actualizarCantIncidentes(NodoPoliza *lista,Incidente incidente)
{
    NodoPoliza *p;
    p=buscarXnroPoliza(lista, incidente.nroPolisa);
    if(p)
    {
        p->poliza.cantIncidentes=+1;
        if(compararAnio(incidente))
        {
            p->cant2020=+1;
        }
    }
    else
    {
        cout<<"no se encontro la poliza "<<endl;
    }
    return;
}
Incidente leerIncidente()
{
    Incidente incidente;
    cout<<" codigo"<<endl;
    cin>>incidente.codigoIncidente;
    cout<<"altura"<<endl;
    cin>>incidente.altura;
    cout<<"nroPoliza"<<endl;
    cin>>incidente.nroPolisa;
    cout<<"DNI_asegurado"<<endl;
    scanf("%s",incidente.dniAsegurado);
    cout<<"DNI_otro"<<endl;
    scanf("%s",incidente.dniOtro);
    cout<<"calle"<<endl;
    scanf("%s",incidente.calle);
    cout<<"fechaHora aaaammddhh:mm"<<endl;
    scanf("%s", incidente.fechaHora);
    return incidente;

}
void escribirArchivoIncidentes(char nom[])
{
    FILE *f=fopen(nom,"wb");
    Incidente incidente;
    int op;
    cout<<"\t\t\tingrese incidentes"<<endl;
    do
    {
        incidente=leerIncidente();
        fwrite(&incidente, sizeof(Incidente),1,f);
        cout<<"continuar:1  terminar:2  "<<endl;
        cin>>op;
    }
    while(op==1);
    fclose(f);
}

void procesarLote(NodoPoliza *lista,char lote[],char procesados[])
{
    FILE *l=fopen(lote,"rb");
    FILE *p=fopen(procesados,"a");
    Incidente incidente;
    fread(&incidente,sizeof(Incidente),1,l);
    while(!feof(l))
    {
        actualizarCantIncidentes(lista,incidente);
        fwrite(&incidente,sizeof(Incidente),1,p);
        fread(&incidente,sizeof(Incidente),1,l);
    }
    fclose(l);
    fclose(p);
    return;
}
int main()
{
    NodoPoliza *lista=NULL;//lista donde se cargaran todas la polizas
    char asegurados[]="asegurados.BAK";
    char procesados[]="procesados.BAK";
    char incidentes[]="incidentes.BAK";
    char elegida;
    do
    {
        elegida= mostrarMenu();
        switch (elegida)
        {
        case '1':
        {
            aseguradosBakPrueba();

            FILE *f=fopen(asegurados,"rb");
            PolisaAsegurado polizaACargar;
            if(f)
            {
                fread(&polizaACargar,sizeof(PolisaAsegurado),1,f);
                while(!feof(f))
                {
                    cargarAlFinal(lista,polizaACargar);
                    fread(&polizaACargar,sizeof(PolisaAsegurado),1,f);
                }
                fclose(f);
            }
            else
            {
                cout<<"error al abrir el archivo"<<endl;
            }
            cout<<"\t\t\tpolizas levantadas de Asegurados.Bak"<<endl;
            mostrarListaPolizas(lista);

        }
        break;
        case '2':
        {
            cout<<"\t\t\t\tingrese los datos De la nueva poliza"<<endl;
            PolisaAsegurado poliza=leerPoliza();
            cargarAlFinal(lista,poliza);
            cout<<"\t\t\t se cargo la nueva poliza"<<endl;

        }
        break;
        case '3':
        {
            int nro;
            cout<<"\t\t\t\tingrese el nro de la poliza a desactivar"<<endl;
            cin>>nro;
            NodoPoliza *p=buscarXnroPoliza(lista,nro);
            if(p)
            {
                p->poliza.activa=false;
                cout<<"\t\t\t\tse desactivo poliza"<<endl;
            }
            else
            {
                cout<<"\t\t\t\tno se encontro la poliza"<<endl;
            }

        }
        break;
        case '4':
        {
            int nroPo;
            NodoPoliza *p;
            cout<<"\t\t\t\tingrese el nro de la poliza a buscar"<<endl;
            cin>>nroPo;
            p=buscarXnroPoliza(lista,nroPo);
            if(p)
            {
                cout<<"\t\t\t\tpoliza coincidente con el nro ingresado"<<endl;
                mostrarPoliza(p->poliza);
            }
            else
            {
                cout<<"\t\t\t\tno se encontraron coincidencias"<<endl;
            }

        }
        break;
        case '5':
        {
            cout<<"\t\t\t\tingrese el dni a buscar xx.xxx.xxx"<<endl;
            char dni[11];
            scanf("%s",dni);
            NodoPoliza *aux=lista;
            cout<<"\t\t\t polizas coincidentes"<<endl;
            while(aux)
            {
                if(!strcmp(aux->poliza.dni,dni))
                {
                    mostrarPoliza(aux->poliza);
                }
                aux=aux->sig;
            }
        }
        break;
        case '6':
        {
            NodoPoliza *polizasActivas=NULL;
            buscarPolizasActivas(lista,polizasActivas);
            mostrarListaPolizas(polizasActivas);
            if(polizasActivas)
            {
                cout<<"\t\t\t\tpolisas activas ordenadas por cant de incidentes"<<endl;
                ordenarListaDescen(polizasActivas);
                mostrarListaPolizas(polizasActivas);
                borrarLista(polizasActivas);
            }
            else
            {
                cout<<"\t\t\t\tno se encontraron polizas activas"<<endl;
            }
        }
        break;
        case '7':
        {
            //loteIncidentesPrueba();
            escribirArchivoIncidentes(incidentes);
            procesarLote(lista,incidentes,procesados);
            cout<<"\t\t\t\tse proceso el lote de incidentes"<<endl;
        }
        break;
        case '8':
        {

            FILE *h=fopen("masDe5Incidentes.html","wt");
            fprintf(h,"<html><body >\n");
            fprintf(h,"<h3>polizas con mas de 5 incidentes en 2020:</h3>\n");
            fprintf(h,"<table border=1>\n");
            fprintf(h,"<th>NroPoliza</th> <th>DOcumento DNI</th> <th>Nombre</th> <th>Apelido</th> <th>CuotaAlDia</th> <th>PatenteAuto</th> <th>Activa</th> <th>CantIncidentes</th>\n");
            NodoPoliza *lista2020=lista;
            while(lista2020!=NULL )
            {
                if(lista2020->cant2020>5)
                {
                    PolisaAsegurado poliza=lista2020->poliza;
                    fprintf(h,"<tr>");
                    fprintf(h,"<td>%d</td>",poliza.nroPoliza);
                    fprintf(h,"<td>%s</td> ",poliza.dni);
                    fprintf(h,"<td>%s</td> ",poliza.nombre);
                    fprintf(h,"<td>%s</td> ",poliza.apellido);
                    fprintf(h,"<td>%d</td> ",poliza.cuotaAlDia);
                    fprintf(h,"<td>%s</td> ",poliza.patente);
                    fprintf(h,"<td>%d</td> ",poliza.activa);
                    fprintf(h,"<td>%d</td> ",poliza.cantIncidentes);
                    fprintf(h,"</tr>");
                }
                lista2020=lista2020->sig;
            }
            fprintf(h,"</table>");
            fprintf(h,"</body>");
            fprintf(h,"</html>");
            fclose(h);
            cout<<"\t\t\t\tse creo el archivo .html con el informe"<<endl;
        }
        break;
        case '9':
        {
            FILE *h=fopen("masDe5Incidentes.csv","wt");
            fprintf(h,"NroPoliza;Documento DNI;Nombre;Apelido;CuotaAlDia;PatenteAuto;Activa;CantIncidentes\n");
            NodoPoliza *lista2020=lista;
            while(lista2020!=NULL )
            {
                if(lista2020->cant2020>5)
                {
                    PolisaAsegurado poliza=lista2020->poliza;
                    fprintf(h,"%d;",poliza.nroPoliza);
                    fprintf(h,"%s;",poliza.dni);
                    fprintf(h,"%s; ",poliza.nombre);
                    fprintf(h,"%s; ",poliza.apellido);
                    fprintf(h,"%d; ",poliza.cuotaAlDia);
                    fprintf(h,"%s; ",poliza.patente);
                    fprintf(h,"%d; ",poliza.activa);
                    fprintf(h,"%d; \n",poliza.cantIncidentes);
                }
                lista2020=lista2020->sig;
            }
            fclose(h);
            cout<<"\t\t\t\tse creo el archivo .csv con el informe"<<endl;
        }
        break;
        case '0':
        {
            NodoPoliza *activas=NULL;
            buscarPolizasActivas(lista, activas);
            if(activas!=NULL)
            {
                escribirListaEnArchivo(activas,asegurados);
                cout<<"\t\t\t\tse cargaron polizas activas a Asegurados.BAK"<<endl;
                borrarLista(lista);
            }
            else
            {
                cout<<"\t\t\t no se cargaron las polizas"<<endl;
            }
        }
        break;
        }
    }
    while (elegida!=27);
    cout<<"\t\t\tFinalizó la jornada" <<endl;
    return 0;
}

