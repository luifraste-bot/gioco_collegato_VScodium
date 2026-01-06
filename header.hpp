#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <iostream>


class oggetto {
    protected:
    std::string nome;
    float peso;
    std::string materiale; //legno,ferro,tungsteno,vetro(pozione)
    public://check
        oggetto(){};
        oggetto(std::string nome,float peso,std::string materiale){
            this->nome=nome;
            this->peso=peso;
            this->materiale=materiale;
        }
        virtual ~oggetto(){};//distruttore che svuota a ogni riavvio
        virtual void stampa_oggetto(){//il virtual mi va a finire in una classe ereditaria caso mai debba stampare oggetti particolari
            std::cout<<"nome dell'oggetto: "<<nome<<std::endl;
            std::cout<<"peso dell'oggetto: "<<peso<<" Kg"<<std::endl;
            std::cout<<"materiale dell'oggetto: "<<materiale<<std::endl;
        }
    void set_nome(std::string nome){this->nome=nome;}
    std::string get_nome(){return nome;}

    void set_nome(float peso){this->peso=peso;}
    int get_peso(){return peso;}

    void set_materiale(std::string materiale){this->materiale=materiale;}
    std::string get_materiale(){return materiale;}
};

class spada:public oggetto{
    std::string affilatezza;
public:
    spada(){};//pure se non metto il costruttore vuoto � come se il codice dicesse "Costruisci prima l�oggetto base con questi valori, poi costruisci la parte spada." al compilatore.Basta che metto il costruttore vuoto nella classe madre oggetto
    spada(std::string nome,float peso,std::string materiale,std::string affilatezza):oggetto(nome,peso,materiale){
        this->affilatezza=affilatezza;
    }
    void set_affilatezza(int affilatezza){this->affilatezza=affilatezza;}
    std::string get_affilatezza(){return affilatezza;}

     void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"affilatezza: "<<affilatezza<<std::endl;
        }

};

class pozione:public oggetto{
    std::string effetto;//cura,danno,veleno
public:
    pozione(){};
    pozione(std::string nome,float peso,std::string materiale,std::string effetto):oggetto(nome,peso,materiale){
        this->effetto=effetto;
    }
    void set_effetto(std::string effetto){this->effetto=effetto;}
    std::string get_effetto(){return effetto;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"effetto: "<<effetto<<std::endl;
        }

};




class martello:public oggetto{
    std::string grandezza;//cura,danno,veleno
public:
    martello(){};
    martello(std::string nome,float peso,std::string materiale,std::string grandezza):oggetto(nome,peso,materiale){
        this->grandezza=grandezza;
    }
    void set_grandezza(std::string grandezza){this->grandezza=grandezza;}
    std::string get_grandezza(){return grandezza;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"grandezza: "<<grandezza<<std::endl;
        }

};

class armatura:public oggetto{
    std::string protezione;//cura,danno,veleno
public:
    armatura(){};
    armatura(std::string nome,int peso,std::string materiale,std::string protezione):oggetto(nome,peso,materiale){
        this->protezione=protezione;
    }
    void set_protezione(std::string protezione){this->protezione=protezione;}
    std::string get_protezione(){return protezione;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"protezione: "<<protezione<<std::endl;
        }

};

class bomba:public oggetto{
    std::string esplosivita;//cura,danno,veleno
public:
    bomba(){};
    bomba(std::string nome,double peso,std::string materiale,std::string esplosivita):oggetto(nome,peso,materiale){
        this->esplosivita=esplosivita;
    }
    void set_esplosivita(std::string esplosivita){this->esplosivita=esplosivita;}
    std::string get_esplosivita(){return esplosivita;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"esplosivita': "<<esplosivita<<std::endl;
        }

};

class sacc_di_monete:public oggetto{
    std::string monete;//cura,danno,veleno
public:
    sacc_di_monete(){};
    sacc_di_monete(std::string nome,double peso,std::string materiale,std::string monete):oggetto(nome,peso,materiale){
        this->monete=monete;
    }
    void set_monete(std::string monete){this->monete=monete;}
    std::string get_monete(){return monete;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"monete: "<<monete<<std::endl;
        }

};

class balestra:public oggetto{
    std::string pstrazione;//cura,danno,veleno
public:
    balestra(){};
    balestra(std::string nome,int peso,std::string materiale,std::string pstrazione):oggetto(nome,peso,materiale){
        this->pstrazione=pstrazione;
    }
    void set_pstrazione(std::string pstrazione){this->pstrazione=pstrazione;}
    std::string get_pstrazione(){return pstrazione;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            std::cout<<"pstrazione: "<<pstrazione<<std::endl;
        }

};


class giocatore {

    std::string nome, cognome;

    //oggetto* inv[6];//inventario

    static const int max_inv=20;//massimo 20 slot ma all'avventuriero ne diamo di piu
    oggetto* inv[max_inv];
    int n_ogg=0;//partiamo con zero oggetti
    int spazio_inv=6;
    int DEX;
    int STR;
    int HP;
    int MP;
  public:
      giocatore(){
        for(int i=0;i<max_inv;i++){
            inv[i]=nullptr;//mi dice che nello slot non ce nulla
        }
      };
      ~giocatore(){//distruttore
          for(int i=0;i<n_ogg;i++){
            delete inv[i];//mi cancella tutti gli oggetti dinamici dall'inventario
          }
      }
      giocatore(std::string nome,std::string cognome,int DEX,int STR,int HP,int MP,int n_ogg,int spazio_inv){
        this->nome=nome;
        this->cognome=cognome;
        this->DEX=DEX;
        this->STR=STR;
        this->HP=HP;
        this->MP=MP;
        this->n_ogg=n_ogg;
        this->spazio_inv=spazio_inv;
      }
    void set_nome(std::string nome){this->nome=nome;}//quando mi richiamo queste funzione all'interno della classe gioco  quando faccio std::cin>> nome inserisco il nome e la funzione  questa qui me lo inserisce
    std::string get_nome(){return nome;}

    void set_cognome(std::string cognome){this->cognome=cognome;}
    std::string get_cognome(){return cognome;}

    void set_DEX(int DEX){this->DEX=DEX;}
    int get_DEX(){return DEX;}

    void set_STR(int STR){this->STR=STR;}
    int get_STR(){return STR;}

    void set_HP(int HP){this->HP=HP;}
    int get_HP(){return HP;}

    void set_MP(int MP){this->MP=MP;}
    int get_MP(){return MP;}

    void set_spazio_inv(int spazio_inv){this->spazio_inv=spazio_inv;}
    int get_spazio_inv(){return spazio_inv;}


    int update_DEX(int& DEX,int x){//CAPISCI PERCHE NO TI FA L'UPDATE DELLE CARATTERISTICHE
        DEX=DEX+x;
        void set_DEX(int DEX);
        std::cout<<"destrezza: "<<DEX<<std::endl;
        return DEX;
    }
    int updown_DEX(int& DEX,int x){
        DEX=DEX-x;
        void set_DEX(int DEX);
        std::cout<<"destrezza: "<<DEX<<std::endl;
        return DEX;
    }
    int update_HP(int& HP,int x){
        HP=HP+x;
        void set_HP(int HP);
        std::cout<<"salute: "<<HP<<std::endl;
        return HP;
    }
    int updown_HP(int& HP,int x){
        HP=HP-x;
        void set_HP(int HP);
        std::cout<<"salute: "<<HP<<std::endl;
        return HP;
    }
    int update_STR(int& STR,int x){
        STR=STR+x;
        void set_STR(int STR);
        std::cout<<"forza: "<<STR<<std::endl;
        return STR;
    }
    int updown_STR(int& STR,int x){
        STR=STR-x;
        void set_STR(int STR);
        std::cout<<"forza: "<<STR<<std::endl;
        return STR;
    }
    int update_MP(int& MP,int x){
        MP=MP+x;
        void set_MP(int MP);
        std::cout<<"mana: "<<MP<<std::endl;
        return MP;
    }
    int updown_MP(int& MP,int x){
        MP=MP-x;
        void set_MP(int MP);
        std::cout<<"mana: "<<MP<<std::endl;
        return MP;
    }


    void set_n_ogg(int n_ogg){this->n_ogg=n_ogg;} //questo non mi serve perche parti con zero oggetti
    int get_n_ogg(){return n_ogg;}
    void AugNum_ogg(){n_ogg++;}  //aumenta solo di 1
    //void AugNum_ogg(int quantita) {n_ogg += quantita;}//se voglio aumentare idi una certa quantit�
    int get_num_ogg(){return n_ogg;}


    void aggiungi_oggetto(oggetto* ogg){//mi passa l'oggeto che io richiamo per riferimento quindi mi prende l'oggetto vero e proprio e non me lo copia
        if (n_ogg<spazio_inv){
            inv[n_ogg]=ogg;//gli oggetti vengo inseriti in modo ordinato dalla prima alla sesta posizione
            n_ogg++;
        }else{
            std::cout<<"inventario pieno"<<std::endl;
        }
    }

    void stampa_inventario(){
        std::cout<<"il tuo inventario:("<<n_ogg<<"/"<<spazio_inv<<")"<<std::endl;
        for(int i=0;i<n_ogg;i++){
            inv[i]->stampa_oggetto();//richiamo la funzione perstampare l'oggetto
            std::cout<<std::endl;
        }
    }

    void update_character(int& DEX,int& STR,int& HP,int& MP){
        void set_DEX(int DEX);
        void set_STR(int STR);
        void set_HP(int HP);
        void set_MP(int MP);
    }

    void stampa_character(int& DEX,int& STR,int& HP,int& MP){//passiamo i parametri per riferimento in modo che  quando li chiamo nel codice questi si aggiornino per davvero e non apparentemente--------------------------------------------------------------------------------------------------------------------------------------
        std::cout<<"Le tue statistiche..."<<std::endl;
        std::cout<<"---------------------"<<std::endl;
        std::cout<<"Destrezza : "<<DEX<<std::endl;
        std::cout<<"Forza : "<<STR<<std::endl;
        std::cout<<"Salute : "<<HP<<std::endl;
        std::cout<<"Mana : "<<MP<<std::endl;
    }


    //ricerca sequenziale per trovsarfe il sacchetto di monete in modo da far apparire la terza sceltyaa nella storia del mercenario

    std::string CheckInventarioSacchetto(int spazio_inventario){
        for(int i=0;i<spazio_inventario;i++){
            if(inv[i]!=nullptr && inv[i]->get_nome()=="sacchetto di monete"){//nullptr se trova una casella vuota non mi fa crashare3
                return inv[i]->get_nome();
            }
        }
        return "non hai il sacchetto di monete";
    };




};

class partita{
    std::string nome;        //es...gioco
    giocatore G[2];     //successivamente vediamo come mettere il bot
    int n_giocatori;    //il num giocatori lo scelgi nell int main
    int DEX_g;
    int STR_g;
    int HP_g;
    int MP_g;
    int choice;
    int character;
public:



    partita(){};
    void set_giocatore(int pos){
        std::string nome_g;
        std::cout<<"inserisci nome"<<std::endl;
        std::cin>>nome_g;
        G[pos].set_nome(nome_g);

        /* NON CI SERVE IL COGNOME
        std::string cognome_g;
        std::cout<<"inserisci cognome"<<std::endl;
        std::cin>>cognome_g;
        G[pos].set_cognome(cognome_g);
*/



        // *scegli la classe* //
        std::cout<<"scegli la tua classe (1-4)"<<std::endl;
        std::cout<<"     "<<std::endl;
        std::cout<<"scegli tra: "<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"1) Assassino"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"2) Mago"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"3) Mercenario"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"4) Avventuriero"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cin>>character;
        int app;
        std::string app2;
        //penso che dobbiamo mettere in ordine hp str dex e mp

        switch (character){
            case 1:
                std::cout<<"hai scelto l'assassino!"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"la tua Destrezza"<<std::endl;
                DEX_g=80;
                std::cout<<"Destrezza : "<<DEX_g<<std::endl;
                G[pos].set_DEX(DEX_g);

                std::cout<<"la tua Forza"<<std::endl;
                STR_g=89;
                std::cout<<"Forza : "<<STR_g<<std::endl;
                G[pos].set_STR(STR_g);

                std::cout<<"la tua Salute"<<std::endl;
                HP_g=63;
                std::cout<<"Salute : "<<HP_g<<std::endl;
                G[pos].set_HP(HP_g);

                std::cout<<"la tua Mana"<<std::endl;
                MP_g=47;
                std::cout<<"Mana : "<<MP_g<<std::endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 2:
                std::cout<<"hai scelto il mago!"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"la tua Destrezza"<<std::endl;
                DEX_g=78;
                std::cout<<"Destrezza : "<<DEX_g<<std::endl;
                G[pos].set_DEX(DEX_g);

                std::cout<<"la tua Forza"<<std::endl;
                STR_g=46;
                std::cout<<"Forza : "<<STR_g<<std::endl;
                G[pos].set_STR(STR_g);

                std::cout<<"la tua Salute"<<std::endl;
                HP_g=55;
                std::cout<<"Salute : "<<HP_g<<std::endl;
                G[pos].set_HP(HP_g);

                std::cout<<"la tua Mana"<<std::endl;
                MP_g=95;
                std::cout<<"Mana : "<<MP_g<<std::endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 3:
                std::cout<<"hai scelto il mercenario!"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"la tua Destrezza"<<std::endl;
                DEX_g=75;
                std::cout<<"Destrezza : "<<DEX_g<<std::endl;
                G[pos].set_DEX(DEX_g);

                std::cout<<"la tua Forza"<<std::endl;
                STR_g=79;
                std::cout<<"Forza : "<<STR_g<<std::endl;
                G[pos].set_STR(STR_g);

                std::cout<<"la tua Salute"<<std::endl;
                HP_g=88;
                std::cout<<"Salute : "<<HP_g<<std::endl;
                G[pos].set_HP(HP_g);

                std::cout<<"la tua Mana"<<std::endl;
                MP_g=30;
                std::cout<<"Mana : "<<MP_g<<std::endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 4:
                std::cout<<"hai scelto l'avventuriero!"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"la tua Destrezza"<<std::endl;
                DEX_g=65;
                std::cout<<"Destrezza : "<<DEX_g<<std::endl;
                G[pos].set_DEX(DEX_g);

                std::cout<<"la tua Forza"<<std::endl;
                STR_g=70;
                std::cout<<"Forza : "<<STR_g<<std::endl;
                G[pos].set_STR(STR_g);

                std::cout<<"la tua Salute"<<std::endl;
                HP_g=75;
                std::cout<<"Salute : "<<HP_g<<std::endl;
                G[pos].set_HP(HP_g);

                std::cout<<"la tua Mana"<<std::endl;
                MP_g=60;
                std::cout<<"Mana : "<<MP_g<<std::endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(12);
                G[pos].get_spazio_inv();

                break;
            case 5:
                std::cout<<"hai scelto il carabiniere!"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"la tua Destrezza"<<std::endl;
                DEX_g=999;
                std::cout<<"Destrezza : "<<DEX_g<<std::endl;
                G[pos].set_DEX(DEX_g);

                std::cout<<"la tua Forza"<<std::endl;
                STR_g=999;
                std::cout<<"Forza : "<<STR_g<<std::endl;
                G[pos].set_STR(STR_g);

                std::cout<<"la tua Salute"<<std::endl;
                HP_g=999;
                std::cout<<"Salute : "<<HP_g<<std::endl;
                G[pos].set_HP(HP_g);

                std::cout<<"la tua Mana"<<std::endl;
                MP_g=999;
                std::cout<<"Mana : "<<MP_g<<std::endl;
                G[pos].set_MP(MP_g);
                break;

        }


        switch (character){
        case 1:{
            std::cout<<"---storia Assassino---"<<std::endl;
            //storia
            //1 SCELTA
            std::cout<<R"(sei un uomo di poche parole, un uomo senza passato, hai un lavoro semplice, entrare nel Dungeon, uccidere chiunque sia dentro, e portare il bottino a chi ti ha pagato, per iniziare scegli di portare...)"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"scegli :"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"1)la tua fidata balestra"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"2)il tuo efficace coltello"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cin>>choice;

            switch(choice){
                case 1:{
                    std::cout<<R"(la balestra fara un buon lavoro, silenziosa, efficace, letale)"<<std::endl;

                    oggetto* b=new balestra("balestra",1,"legno","leggero");
                    G[pos].aggiungi_oggetto(b);
                    G[pos].stampa_inventario();

                    break;
                }
                case 2:{
                    std::cout<<R"(il coltello sara alquanto utile, semplice,efficace)"<<std::endl;

                    oggetto* c=new spada("coltello",0.2,"acciaio","come un rasoio");
                    G[pos].aggiungi_oggetto(c);
                    G[pos].stampa_inventario();

                    break;
                }
            }
            //2 SCELTA
            std::cout<<R"(Armi solite da sole non basteranno, quindi e� meglio portare anche qualche oggetto�alternativo come...)"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"scegli :"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"1)bomba"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"2)fiala di veleno"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cin>>choice;

            switch(choice){
                case 1:{
                    std::cout<<R"( rumoroso, ma funzionale, ti sara� di uso, e� un po caotico, ma andra� bene)"<<std::endl;

                    oggetto* b=new bomba("bomba",0.5,"polvere da sparo","alta");
                    G[pos].aggiungi_oggetto(b);
                    G[pos].stampa_inventario();
                    break;
                }
                case 2:{
                    std::cout<<R"(solito e semplice, nulla da lavare, un metodo pulito e efficace)"<<std::endl;

                    oggetto* p=new pozione("fiala velenosa",0.1,"vetro","velenoso");
                    G[pos].aggiungi_oggetto(p);
                    G[pos].stampa_inventario();
                    break;
                }
            }
            //3 SCELTA
            std::cout<<R"(e per finire il capolavoro...)"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"scegli :"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"1)pozione di salute"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"2)un po� di pratica prima di andare"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cin>>choice;

            switch(choice){
                case 1:{
                    std::cout<<"-----"<<std::endl;
                    std::cout<<"R(giusto in caso, e� sempre utile)"<<std::endl;
                    std::cout<<"-----"<<std::endl;
                    std::cout<<"Ottieni: pozione curativa."<<std::endl;//trova scopo sacchetto monete
                    std::cout<<"-----"<<std::endl;

                    oggetto* p=new pozione("pozione curativa",0.1,"vetro","curativo");
                    G[pos].aggiungi_oggetto(p);
                    G[pos].stampa_inventario();
                break;
                }
                case 2:{
                    std::cout<<"-----"<<std::endl;
                    std::cout<<R"(meglio tenersi affilati quanto il proprio armamento� (+10 tutto))"<<std::endl;
                    std::cout<<"-----"<<std::endl;
                    std::cout<<"Ottieni: +10 ad ogni statistica."<<std::endl;//trova scopo sacchetto monete
                    std::cout<<"-----"<<std::endl;

                    app=G[pos].update_STR(STR_g,10);
                    G[pos].set_STR(app);
                    app=G[pos].update_DEX(DEX_g,10);
                    G[pos].set_DEX(app);
                    app=G[pos].update_HP(HP_g,10);
                    G[pos].set_HP(app);
                    app=G[pos].update_MP(MP_g,10);
                    G[pos].set_MP(app);
                    G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                break;
                }
            }
            //4 SCELTA
            std::cout<<R"(e cosi� sei arrivato, nessuna scelta oltre ad entrare in questo dungeoun)"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"scegli :"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::cout<<"1)entra nel dungeoun"<<std::endl;
            std::cout<<"----------"<<std::endl;
            std::string choice2;//per chiamare il codice konami
            std::cin>>choice2;

            if(choice2=="1"){
            std::cout<<"----------"<<std::endl;
            std::cout<<R"(cosi' inizia la tua avventura)"<<std::endl;
            std::cout<<"----------"<<std::endl;
            }
            else if (choice2=="^^vv<><>ba"){
                std::cout<<"prova a chiamarti carabiniere al inizio del gioco"<<std::endl;
            }

            break;
        }
        case 2:{//storia mago---------------
            std::cout<<"---storia Mago---"<<std::endl;


            //storia
            break;
        }//------------------------------------------------------
        case 3:{
            std::cout<<"---storia Mercenario---"<<std::endl;//------------------------------------------------------------------------------------------------------
            //storia
                std::cout<<"sei un baldo giovine senza lavoro, tuo padre era un fabbro"<<std::endl;
                std::cout<<"e sosteneva la tua famiglia, purtroppo e' morto di pneumonia"<<std::endl;
                std::cout<<"e tocca a te l'essere l'uomo della casa, decidi di diventare un mercenario."<<std::endl;
                std::cout<<"Vai nell'armeria di tuo padre, prendi la sua giornea di cuoio e per armarti prendi..."<<std::endl;

                //giornea di cuoio
                oggetto* a=new armatura("Giornea di cuoio",1,"cuoio","leggera");
                G[pos].aggiungi_oggetto(a);

                std::cout<<"scegli :"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"1)Il suo martello da fabbro"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"2)Il suo spadino e boccolino da torneo"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"3)L' alabarda commissionatagli dalla guarnigione locale"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"4)La spada bastarda tenuta da generazioni"<<std::endl;
                std::cin>>choice;

                    switch(choice){
                        case 1:{
                            //std::cout<<R"()"<<std::endl; COPIA E INCOLLA
                            std::cout<<R"(dopo aver preso il suo martello realizzasti che era pesante,ti sei allenato con esso finche' la tua costituzione non lo fece pesare piu' di una piuma e hai iniziato il tuo lavoro.)"<<std::endl;
                            std::cout<<"-----"<<std::endl;
                            std::cout<<"Ottieni: Martello, +5 STR, +5 HP "<<std::endl;
                            std::cout<<"-----"<<std::endl;

                            app=G[pos].update_STR(STR_g,5);//aumenta di quanto inserisco
                            G[pos].set_STR(app);

                            app=G[pos].update_HP(HP_g,5);//aumenta di quanto inserisco
                            G[pos].set_HP(app);
                            oggetto* m=new martello("Martello_da_Fabbro",0.5,"ferro","affilata");
                                    G[pos].aggiungi_oggetto(m);
                                    G[pos].stampa_inventario();

                                    //funzione update  i parametri che me li setta come nuovi in modo da mantenerli aggiornati
                                    //dovrebbe contenere tanti G[pos].set_DEX(DEX_g) e per il resto degli attributi
                                    //dovrebbe andare prima del stampa character ovviamente

                                    //G[pos].update_character(DEX_g,STR_g,HP_g,MP_g);

                                    G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);//COPIA E INCOLLA DOVE SERVE----------------------------------------------------------
                                    break;
                    }
                        case 2:{
                                std::cout<<R"(dopo aver preso lo spadino e il boccolino ti sei allenato ad usare queste armi di destrezza finche' non eri pi� pi� lesto di Achille stesso, ti senti pronto per il tuo lavoro.)"<<std::endl;
                                std::cout<<"-----"<<std::endl;
                                std::cout<<"Ottieni: Spadino & Boccolino, giornea di cuoio, +10 DEX. "<<std::endl;
                                std::cout<<"-----"<<std::endl;

                                    app=G[pos].update_DEX(DEX_g,10);//aumenta di quanto inserisco
                                    G[pos].set_DEX(app);
                                    oggetto* s=new spada("Spadino & Boccolino",0.5,"ferro","affilata");
                                    G[pos].aggiungi_oggetto(s);

                                    G[pos].stampa_inventario();
                                    G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                                    break;
                    }
                        case 3:{
                                std::cout<<R"(dopo aver preso l�alabarda realizzi che quest� arma e� al quanto ingombrante, la tua forza non � abbastanza per tenerla bene quindi ti alleni, ma non sei capace di essere lesto con un simile armamenti, in ogni caso sei pronto per il tuo lavoro.)"<<std::endl;
                                std::cout<<"-----"<<std::endl;
                                std::cout<<"Ottieni: Alabarda, giornea di cuoio, +10 STR, -10 DEX. "<<std::endl;
                                std::cout<<"-----"<<std::endl;

                                app=G[pos].update_STR(STR_g,10);
                                G[pos].set_STR(app);
                                app=G[pos].updown_DEX(DEX_g,10);
                                G[pos].set_DEX(app);
                                oggetto* s=new spada("Alabarda",3,"ferro","smussata");
                                G[pos].aggiungi_oggetto(s);
                                oggetto* a=new armatura("Giornea di cuoio",1,"cuoio","leggera");
                                G[pos].aggiungi_oggetto(a);
                                G[pos].stampa_inventario();
                                G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                            break;
                    }
                        case 4:{
                                std::cout<<R"(dopo aver preso questa spada appartenente alla tua famiglia da generazioni sei riempito da un senso di orgoglio, non ti pesa nulla a tenerla, e' come se fosse fata proprio per te, sei travolto dalla vitalitA' lasciata a te dai tuoi antenati, sei pronto per il tuo lavoro.)"<<std::endl;
                                std::cout<<"-----"<<std::endl;
                                std::cout<<"Ottieni: Spada Bastarda, giornea di cuoio, +25HP. "<<std::endl;
                                std::cout<<"-----"<<std::endl;

                                app=G[pos].update_HP(HP_g,25);//aumenta di quanto inserisco
                                G[pos].set_HP(app);
                                oggetto* s=new spada("Spada_Bastarda",1,"acciaio","smussata");
                                G[pos].aggiungi_oggetto(s);
                                oggetto* a=new armatura("Giornea di cuoio",1,"cuoio","leggera");
                                G[pos].aggiungi_oggetto(a);
                                G[pos].stampa_inventario();
                                G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                            break;
                    }

                }
                //2nd scelta
                std::cout<<R"(ti sono offerti 3 lavori che puoi fare, un nobile ti desidera come guardia del corpo nel suo viaggio verso una grande citta�, la guarnigione locale vuole assumerti come guardia per non lasciare dei prigionieri fuggire e un cavaliere ti vuole come scudiero per la sua prossima avventura, decidi di�)"<<std::endl;

                std::cout<<"scegli :"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"1)fare da guardia al nobile"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"2)arruolarti della guarnigione locale"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"3)diventa uno scudiero "<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cin>>choice;

                switch(choice){
                    case 1:{
                        std::cout<<R"(lavorare per il nobile, mentre viaggi con il nobile dei briganti fermano la vostra carovana, lo difendi lealmente ma vieni attaccato nel caos, il tuo tendone e stato tagliato rendendoti zoppo, il nobile e� fuggito e ti ha lasciato per morto, zoppichi a casa e ti prepari per un altro arduo giorno di lavoro)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: -10HP, -25DEX. "<<std::endl;
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].updown_HP(HP_g,10);
                        G[pos].set_HP(app);
                        app=G[pos].updown_DEX(DEX_g,25);
                        G[pos].set_DEX(app);
                        G[pos].stampa_inventario();
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                    break;
                    }
                    case 2:{
                        std::cout<<R"(ti arruoli nella guarnigione locale, ti e� data una nuova corazza, fai da guardia alla cella di un criminale ben conosciuto, non dormi per prevenire alcun tentativo di fuga e vieni pagato un modesto stipendio, dopo questa esperienza realizzi che essere una guardia non e' per te, ti prepari per un altro lavoro domani)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: sacchetto di monete, corazza in maglia di ferro(-5 DEX) "<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].updown_DEX(DEX_g,5);
                        G[pos].set_DEX(app);
                        oggetto* s=new sacc_di_monete("sacchetto di monete",0.2,"oro","abbastanza");
                        G[pos].aggiungi_oggetto(s);
                        oggetto* a=new armatura("corazza in maglia di ferro",15,"ferro","pesante");
                        G[pos].aggiungi_oggetto(a);
                        G[pos].stampa_inventario();
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        //fai sacchetto
                    break;
                    }
                    case 3:{
                        std::cout<<R"(diventare uno scudiero per un giorno, non molto succede e per la tua semplice assistenza vieni ripagato, saluti il cavaliere e ti prepari per un altro lavoro domani)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: sacchetto di monete, pozione di salute. "<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        oggetto* s=new sacc_di_monete("sacchetto di monete",0.5,"argento","molte");
                        G[pos].aggiungi_oggetto(s);
                        oggetto* p=new pozione("pozione di salute",0.1,"vetro","cura");
                        G[pos].aggiungi_oggetto(p);
                        G[pos].stampa_inventario();
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                    break;
                    }
                }
                //3nd scelta
                std::cout<<R"(continui a fare lavori dopo lavori e diventi un mercenario al quanto famoso, alcuni vanno bene, altri no, ma in ogni caso, sei vivo, decidi di prendere il giorno libero per mettere la tua vita in ordine quindi decidi di�)"<<std::endl;

                std::cout<<"scegli :"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"1)spendere un po' di tempo con la tua famiglia"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"2)allenarti per passare il tempo"<<std::endl;
                std::cout<<"----------"<<std::endl;

                app2=G[pos].CheckInventarioSacchetto(6);
                if(app2=="sacchetto di monete"){
                    std::cout<<"3)vai a fare compere per equipaggiamento migliore "<<std::endl;//(appare solo se hai borsa di monete) ricerca sequenziale che se torva il sacco di monete ti fa uscire la scelta
                }
                else std::cout<<"terza scelta non presente perche' non hai il sacchetto di monete"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cin>>choice;

                switch(choice){
                    case 1:{
                        std::cout<<R"(spendi la tua giornata con la tua famiglia, ti diverti, ti rilassi, le ferite di battagli passate sono come svanite, sei pronto per un'altra giornata...)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: +25HP."<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].update_HP(HP_g,25);
                        G[pos].set_HP(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        break;
                    }
                    case 2:{
                        std::cout<<R"(passi il tempo ad allenarti, ormai ti viene naturale, non puoi fare altro che passare fluidamente da una mossa alla altra, cosi continui e continui, e� tutto cio� che conosci ormai, ti senti pronto alle tue prossime avventure�)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: +10 ATK, +10 DEX."<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].update_STR(STR_g,10);
                        G[pos].set_STR(app);
                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                        break;
                    }
                    case 3:{
                        std::cout<<R"(trovi una bellissima corazza in acciaio e decidi di comprarla, ti senti piu� pronto alle tue prossime avventure...)"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: corazza in acciaio"<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].updown_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        oggetto* a=new armatura("armatura in acciaio",25,"acciaio","pesante");
                        G[pos].aggiungi_oggetto(a);
                        G[pos].stampa_inventario();
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        break;
                    }
                }
                //4th scelta
                std::cout<<R"(senti di un famoso Dungeon nelle vistd::cinanze e senti la necessita di andarci, magari troverai del tesoro nei suoi antichi corridoi, decidi di...)"<<std::endl;

                std::cout<<"scegli :"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"1)correre li per essere il primo a trovare alcun tesoro"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"2)preparati portando qualche oggetto curativo"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cout<<"3)preparati allenandoti un po'"<<std::endl;
                std::cout<<"----------"<<std::endl;
                std::cin>>choice;

                switch(choice){
                    case 1:{
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: +10 DEX"<<std::endl;
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                        break;
                    }
                    case 2:{

                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: pozione curativa."<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        oggetto* p=new pozione("pozione curativa",0.1,"vetro","curativo");
                        G[pos].aggiungi_oggetto(p);
                        G[pos].stampa_inventario();

                        std::cout<<"-----"<<std::endl;
                        std::cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        break;
                        }
                    case 3:{

                        std::cout<<"-----"<<std::endl;
                        std::cout<<"Ottieni: +10 ad ogni statistica."<<std::endl;//trova scopo sacchetto monete
                        std::cout<<"-----"<<std::endl;

                        app=G[pos].update_STR(STR_g,10);
                        G[pos].set_STR(app);
                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        app=G[pos].update_HP(HP_g,10);
                        G[pos].set_HP(app);
                        app=G[pos].update_MP(MP_g,10);
                        G[pos].set_MP(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        std::cout<<"-----"<<std::endl;
                        std::cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<std::endl;
                        std::cout<<"-----"<<std::endl;
                        break;
                    }
                }

        break;//del case 3 sopra
        }
        case 4:{
            std::cout<<"---storia Avventuriero---"<<std::endl;
            //storia
            break;
        }
        case 5:{
            std::cout<<"---storia Carabiniere---"<<std::endl;
            //storia
            break;
        }
    }

    };
    giocatore get_giocatore(int pos){return G[pos];}

    void CaricaGiocatore(int N){
        n_giocatori=N;
        for(int i=0;i<N;i++){
            set_giocatore(i);
        }
    }

    void Gioco(){
        int pos=0;
        int pos2=1;//lo uso per riferirmi al giocatore 1
        std::cout<<"Comincia Il Combattimento"<<std::endl;
        std::cout<<G[pos].get_DEX()<<std::endl;//la destrezza rimani cosi com'� non viene modificata
        std::cout<<G[pos2].get_DEX()<<std::endl;//perche al giocatore 2 ci sono valori sfasati? dovevamo mettere uno al posto di 2 nella funzione p.Gioco(1) dell int main
        //std::cout<<G[pos].get_STR()<<std::endl; per testare se era tutto ok

            if(G[pos].get_DEX()>G[pos2].get_DEX()){//INIZIA CHI HA PIU DESTREZZA
                std::cout<<"inizia G1"<<std::endl;
            }
            else{
                std::cout<<"inizia G2"<<std::endl;

            }



    }





};


#endif // HEADER_H_INCLUDED
