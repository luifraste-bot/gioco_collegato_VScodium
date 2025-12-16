#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class oggetto {
    protected:
    string nome;
    float peso;
    string materiale; //legno,ferro,tungsteno,vetro(pozione)
    public://check
        oggetto(){};
        oggetto(string nome,float peso,string materiale){
            this->nome=nome;
            this->peso=peso;
            this->materiale=materiale;
        }
        virtual ~oggetto(){};//distruttore che svuota a ogni riavvio
        virtual void stampa_oggetto(){//il virtual mi va a finire in una classe ereditaria caso mai debba stampare oggetti particolari
            cout<<"nome dell'oggetto: "<<nome<<endl;
            cout<<"peso dell'oggetto: "<<peso<<" Kg"<<endl;
            cout<<"materiale dell'oggetto: "<<materiale<<endl;
        }
    void set_nome(string nome){this->nome=nome;}
    string get_nome(){return nome;}

    void set_nome(float peso){this->peso=peso;}
    int get_peso(){return peso;}

    void set_materiale(string materiale){this->materiale=materiale;}
    string get_materiale(){return materiale;}
};

class spada:public oggetto{
    string affilatezza;
public:
    spada(){};//pure se non metto il costruttore vuoto � come se il codice dicesse "Costruisci prima l�oggetto base con questi valori, poi costruisci la parte spada." al compilatore.Basta che metto il costruttore vuoto nella classe madre oggetto
    spada(string nome,float peso,string materiale,string affilatezza):oggetto(nome,peso,materiale){
        this->affilatezza=affilatezza;
    }
    void set_affilatezza(int affilatezza){this->affilatezza=affilatezza;}
    string get_affilatezza(){return affilatezza;}

     void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"affilatezza: "<<affilatezza<<endl;
        }

};

class pozione:public oggetto{
    string effetto;//cura,danno,veleno
public:
    pozione(){};
    pozione(string nome,float peso,string materiale,string effetto):oggetto(nome,peso,materiale){
        this->effetto=effetto;
    }
    void set_effetto(string effetto){this->effetto=effetto;}
    string get_effetto(){return effetto;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"effetto: "<<effetto<<endl;
        }

};




class martello:public oggetto{
    string grandezza;//cura,danno,veleno
public:
    martello(){};
    martello(string nome,float peso,string materiale,string grandezza):oggetto(nome,peso,materiale){
        this->grandezza=grandezza;
    }
    void set_grandezza(string grandezza){this->grandezza=grandezza;}
    string get_grandezza(){return grandezza;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"grandezza: "<<grandezza<<endl;
        }

};

class armatura:public oggetto{
    string protezione;//cura,danno,veleno
public:
    armatura(){};
    armatura(string nome,int peso,string materiale,string protezione):oggetto(nome,peso,materiale){
        this->protezione=protezione;
    }
    void set_protezione(string protezione){this->protezione=protezione;}
    string get_protezione(){return protezione;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"protezione: "<<protezione<<endl;
        }

};

class bomba:public oggetto{
    string esplosivita;//cura,danno,veleno
public:
    bomba(){};
    bomba(string nome,int peso,string materiale,string esplosivita):oggetto(nome,peso,materiale){
        this->esplosivita=esplosivita;
    }
    void set_esplosivita(string esplosivita){this->esplosivita=esplosivita;}
    string get_esplosivita(){return esplosivita;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"esplosivita': "<<esplosivita<<endl;
        }

};

class sacc_di_monete:public oggetto{
    string monete;//cura,danno,veleno
public:
    sacc_di_monete(){};
    sacc_di_monete(string nome,int peso,string materiale,string monete):oggetto(nome,peso,materiale){
        this->monete=monete;
    }
    void set_monete(string monete){this->monete=monete;}
    string get_monete(){return monete;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"monete: "<<monete<<endl;
        }

};

class balestra:public oggetto{
    string pstrazione;//cura,danno,veleno
public:
    balestra(){};
    balestra(string nome,int peso,string materiale,string pstrazione):oggetto(nome,peso,materiale){
        this->pstrazione=pstrazione;
    }
    void set_pstrazione(string pstrazione){this->pstrazione=pstrazione;}
    string get_pstrazione(){return pstrazione;}

    void stampa_oggetto()override{//override mi va a overridare la funzio9ne stampa oggetto originale con questa che permette di stampare l'affilatezza o le altre caratteristiche non ereditarie
            oggetto::stampa_oggetto();
            cout<<"pstrazione: "<<pstrazione<<endl;
        }

};


class giocatore {

    string nome, cognome;

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
      giocatore(string nome,string cognome,int DEX,int STR,int HP,int MP,int n_ogg,int spazio_inv){
        this->nome=nome;
        this->cognome=cognome;
        this->DEX=DEX;
        this->STR=STR;
        this->HP=HP;
        this->MP=MP;
        this->n_ogg=n_ogg;
        this->spazio_inv=spazio_inv;
      }
    void set_nome(string nome){this->nome=nome;}//quando mi richiamo queste funzione all'interno della classe gioco  quando faccio cin>> nome inserisco il nome e la funzione  questa qui me lo inserisce
    string get_nome(){return nome;}

    void set_cognome(string cognome){this->cognome=cognome;}
    string get_cognome(){return cognome;}

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
        cout<<"destrezza: "<<DEX<<endl;
        return DEX;
    }
    int updown_DEX(int& DEX,int x){
        DEX=DEX-x;
        void set_DEX(int DEX);
        cout<<"destrezza: "<<DEX<<endl;
        return DEX;
    }
    int update_HP(int& HP,int x){
        HP=HP+x;
        void set_HP(int HP);
        cout<<"salute: "<<HP<<endl;
        return HP;
    }
    int updown_HP(int& HP,int x){
        HP=HP-x;
        void set_HP(int HP);
        cout<<"salute: "<<HP<<endl;
        return HP;
    }
    int update_STR(int& STR,int x){
        STR=STR+x;
        void set_STR(int STR);
        cout<<"forza: "<<STR<<endl;
        return STR;
    }
    int updown_STR(int& STR,int x){
        STR=STR-x;
        void set_STR(int STR);
        cout<<"forza: "<<STR<<endl;
        return STR;
    }
    int update_MP(int& MP,int x){
        MP=MP+x;
        void set_MP(int MP);
        cout<<"mana: "<<MP<<endl;
        return MP;
    }
    int updown_MP(int& MP,int x){
        MP=MP-x;
        void set_MP(int MP);
        cout<<"mana: "<<MP<<endl;
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
            cout<<"inventario pieno"<<endl;
        }
    }

    void stampa_inventario(){
        cout<<"il tuo inventario:("<<n_ogg<<"/"<<spazio_inv<<")"<<endl;
        for(int i=0;i<n_ogg;i++){
            inv[i]->stampa_oggetto();//richiamo la funzione perstampare l'oggetto
            cout<<endl;
        }
    }

    void update_character(int& DEX,int& STR,int& HP,int& MP){
        void set_DEX(int DEX);
        void set_STR(int STR);
        void set_HP(int HP);
        void set_MP(int MP);
    }

    void stampa_character(int& DEX,int& STR,int& HP,int& MP){//passiamo i parametri per riferimento in modo che  quando li chiamo nel codice questi si aggiornino per davvero e non apparentemente--------------------------------------------------------------------------------------------------------------------------------------
        cout<<"Le tue statistiche..."<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Destrezza : "<<DEX<<endl;
        cout<<"Forza : "<<STR<<endl;
        cout<<"Salute : "<<HP<<endl;
        cout<<"Mana : "<<MP<<endl;
    }


    //ricerca sequenziale per trovsarfe il sacchetto di monete in modo da far apparire la terza sceltyaa nella storia del mercenario

    string CheckInventarioSacchetto(int spazio_inventario){
        for(int i=0;i<spazio_inventario;i++){
            if(inv[i]!=nullptr && inv[i]->get_nome()=="sacchetto di monete"){//nullptr se trova una casella vuota non mi fa crashare3
                return inv[i]->get_nome();
            }
        }
        return "non hai il sacchetto di monete";
    };




};

class partita{
    string nome;        //es...gioco
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
        string nome_g;
        cout<<"inserisci nome"<<endl;
        cin>>nome_g;
        G[pos].set_nome(nome_g);

        /* NON CI SERVE IL COGNOME
        string cognome_g;
        cout<<"inserisci cognome"<<endl;
        cin>>cognome_g;
        G[pos].set_cognome(cognome_g);
*/



        // *scegli la classe* //
        cout<<"scegli la tua classe (1-4)"<<endl;
        cout<<"     "<<endl;
        cout<<"scegli tra: "<<endl;
        cout<<"----------"<<endl;
        cout<<"1) Assassino"<<endl;
        cout<<"----------"<<endl;
        cout<<"2) Mago"<<endl;
        cout<<"----------"<<endl;
        cout<<"3) Mercenario"<<endl;
        cout<<"----------"<<endl;
        cout<<"4) Avventuriero"<<endl;
        cout<<"----------"<<endl;
        cin>>character;
        int app;
        string app2;
        //penso che dobbiamo mettere in ordine hp str dex e mp

        switch (character){
            case 1:
                cout<<"hai scelto l'assassino!"<<endl;
                cout<<"----------"<<endl;
                cout<<"la tua Destrezza"<<endl;
                DEX_g=80;
                cout<<"Destrezza : "<<DEX_g<<endl;
                G[pos].set_DEX(DEX_g);

                cout<<"la tua Forza"<<endl;
                STR_g=89;
                cout<<"Forza : "<<STR_g<<endl;
                G[pos].set_STR(STR_g);

                cout<<"la tua Salute"<<endl;
                HP_g=63;
                cout<<"Salute : "<<HP_g<<endl;
                G[pos].set_HP(HP_g);

                cout<<"la tua Mana"<<endl;
                MP_g=47;
                cout<<"Mana : "<<MP_g<<endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 2:
                cout<<"hai scelto il mago!"<<endl;
                cout<<"----------"<<endl;
                cout<<"la tua Destrezza"<<endl;
                DEX_g=78;
                cout<<"Destrezza : "<<DEX_g<<endl;
                G[pos].set_DEX(DEX_g);

                cout<<"la tua Forza"<<endl;
                STR_g=46;
                cout<<"Forza : "<<STR_g<<endl;
                G[pos].set_STR(STR_g);

                cout<<"la tua Salute"<<endl;
                HP_g=55;
                cout<<"Salute : "<<HP_g<<endl;
                G[pos].set_HP(HP_g);

                cout<<"la tua Mana"<<endl;
                MP_g=95;
                cout<<"Mana : "<<MP_g<<endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 3:
                cout<<"hai scelto il mercenario!"<<endl;
                cout<<"----------"<<endl;
                cout<<"la tua Destrezza"<<endl;
                DEX_g=75;
                cout<<"Destrezza : "<<DEX_g<<endl;
                G[pos].set_DEX(DEX_g);

                cout<<"la tua Forza"<<endl;
                STR_g=79;
                cout<<"Forza : "<<STR_g<<endl;
                G[pos].set_STR(STR_g);

                cout<<"la tua Salute"<<endl;
                HP_g=88;
                cout<<"Salute : "<<HP_g<<endl;
                G[pos].set_HP(HP_g);

                cout<<"la tua Mana"<<endl;
                MP_g=30;
                cout<<"Mana : "<<MP_g<<endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(6);
                G[pos].get_spazio_inv();

                break;
            case 4:
                cout<<"hai scelto l'avventuriero!"<<endl;
                cout<<"----------"<<endl;
                cout<<"la tua Destrezza"<<endl;
                DEX_g=65;
                cout<<"Destrezza : "<<DEX_g<<endl;
                G[pos].set_DEX(DEX_g);

                cout<<"la tua Forza"<<endl;
                STR_g=70;
                cout<<"Forza : "<<STR_g<<endl;
                G[pos].set_STR(STR_g);

                cout<<"la tua Salute"<<endl;
                HP_g=75;
                cout<<"Salute : "<<HP_g<<endl;
                G[pos].set_HP(HP_g);

                cout<<"la tua Mana"<<endl;
                MP_g=60;
                cout<<"Mana : "<<MP_g<<endl;
                G[pos].set_MP(MP_g);

                G[pos].set_spazio_inv(12);
                G[pos].get_spazio_inv();

                break;
            case 5:
                cout<<"hai scelto il carabiniere!"<<endl;
                cout<<"----------"<<endl;
                cout<<"la tua Destrezza"<<endl;
                DEX_g=999;
                cout<<"Destrezza : "<<DEX_g<<endl;
                G[pos].set_DEX(DEX_g);

                cout<<"la tua Forza"<<endl;
                STR_g=999;
                cout<<"Forza : "<<STR_g<<endl;
                G[pos].set_STR(STR_g);

                cout<<"la tua Salute"<<endl;
                HP_g=999;
                cout<<"Salute : "<<HP_g<<endl;
                G[pos].set_HP(HP_g);

                cout<<"la tua Mana"<<endl;
                MP_g=999;
                cout<<"Mana : "<<MP_g<<endl;
                G[pos].set_MP(MP_g);
                break;

        }


        switch (character){
        case 1:{
            cout<<"---storia Assassino---"<<endl;
            //storia
            //1 SCELTA
            cout<<R"(sei un uomo di poche parole, un uomo senza passato, hai un lavoro semplice, entrare nel Dungeon, uccidere chiunque sia dentro, e portare il bottino a chi ti ha pagato, per iniziare scegli di portare...)"<<endl;
            cout<<"----------"<<endl;
            cout<<"scegli :"<<endl;
            cout<<"----------"<<endl;
            cout<<"1)la tua fidata balestra"<<endl;
            cout<<"----------"<<endl;
            cout<<"2)il tuo efficace coltello"<<endl;
            cout<<"----------"<<endl;
            cin>>choice;

            switch(choice){
                case 1:{
                    cout<<R"(la balestra fara un buon lavoro, silenziosa, efficace, letale)"<<endl;

                    oggetto* b=new balestra("balestra",1,"legno","leggero");
                    G[pos].aggiungi_oggetto(b);
                    G[pos].stampa_inventario();

                    break;
                }
                case 2:{
                    cout<<R"(il coltello sara alquanto utile, semplice,efficace)"<<endl;

                    oggetto* c=new spada("coltello",0.2,"acciaio","come un rasoio");
                    G[pos].aggiungi_oggetto(c);
                    G[pos].stampa_inventario();

                    break;
                }
            }
            //2 SCELTA
            cout<<R"(Armi solite da sole non basteranno, quindi e� meglio portare anche qualche oggetto�alternativo come...)"<<endl;
            cout<<"----------"<<endl;
            cout<<"scegli :"<<endl;
            cout<<"----------"<<endl;
            cout<<"1)bomba"<<endl;
            cout<<"----------"<<endl;
            cout<<"2)fiala di veleno"<<endl;
            cout<<"----------"<<endl;
            cin>>choice;

            switch(choice){
                case 1:{
                    cout<<R"( rumoroso, ma funzionale, ti sara� di uso, e� un po caotico, ma andra� bene)"<<endl;

                    oggetto* b=new bomba("bomba",0.5,"polvere da sparo","alta");
                    G[pos].aggiungi_oggetto(b);
                    G[pos].stampa_inventario();
                    break;
                }
                case 2:{
                    cout<<R"(solito e semplice, nulla da lavare, un metodo pulito e efficace)"<<endl;

                    oggetto* p=new pozione("fiala velenosa",0.1,"vetro","velenoso");
                    G[pos].aggiungi_oggetto(p);
                    G[pos].stampa_inventario();
                    break;
                }
            }
            //3 SCELTA
            cout<<R"(e per finire il capolavoro...)"<<endl;
            cout<<"----------"<<endl;
            cout<<"scegli :"<<endl;
            cout<<"----------"<<endl;
            cout<<"1)pozione di salute"<<endl;
            cout<<"----------"<<endl;
            cout<<"2)un po� di pratica prima di andare"<<endl;
            cout<<"----------"<<endl;
            cin>>choice;

            switch(choice){
                case 1:{
                    cout<<"-----"<<endl;
                    cout<<"R(giusto in caso, e� sempre utile)"<<endl;
                    cout<<"-----"<<endl;
                    cout<<"Ottieni: pozione curativa."<<endl;//trova scopo sacchetto monete
                    cout<<"-----"<<endl;

                    oggetto* p=new pozione("pozione curativa",0.1,"vetro","curativo");
                    G[pos].aggiungi_oggetto(p);
                    G[pos].stampa_inventario();
                break;
                }
                case 2:{
                    cout<<"-----"<<endl;
                    cout<<R"(meglio tenersi affilati quanto il proprio armamento� (+10 tutto))"<<endl;
                    cout<<"-----"<<endl;
                    cout<<"Ottieni: +10 ad ogni statistica."<<endl;//trova scopo sacchetto monete
                    cout<<"-----"<<endl;

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
            cout<<R"(e cosi� sei arrivato, nessuna scelta oltre ad entrare in questo dungeoun)"<<endl;
            cout<<"----------"<<endl;
            cout<<"scegli :"<<endl;
            cout<<"----------"<<endl;
            cout<<"1)entra nel dungeoun"<<endl;
            cout<<"----------"<<endl;
            string choice2;//per chiamare il codice konami
            cin>>choice2;

            if(choice2=="1"){
            cout<<"----------"<<endl;
            cout<<R"(cosi' inizia la tua avventura)"<<endl;
            cout<<"----------"<<endl;
            }
            else if (choice2=="^^vv<><>ba"){
                cout<<"prova a chiamarti carabiniere al inizio del gioco"<<endl;
            }

            break;
        }
        case 2:{//storia mago---------------
            cout<<"---storia Mago---"<<endl;


            //storia
            break;
        }//------------------------------------------------------
        case 3:{
            cout<<"---storia Mercenario---"<<endl;//------------------------------------------------------------------------------------------------------
            //storia
                cout<<"sei un baldo giovine senza lavoro, tuo padre era un fabbro"<<endl;
                cout<<"e sosteneva la tua famiglia, purtroppo e' morto di pneumonia"<<endl;
                cout<<"e tocca a te l'essere l'uomo della casa, decidi di diventare un mercenario."<<endl;
                cout<<"Vai nell'armeria di tuo padre, prendi la sua giornea di cuoio e per armarti prendi..."<<endl;

                //giornea di cuoio
                oggetto* a=new armatura("Giornea di cuoio",1,"cuoio","leggera");
                G[pos].aggiungi_oggetto(a);

                cout<<"scegli :"<<endl;
                cout<<"----------"<<endl;
                cout<<"1)Il suo martello da fabbro"<<endl;
                cout<<"----------"<<endl;
                cout<<"2)Il suo spadino e boccolino da torneo"<<endl;
                cout<<"----------"<<endl;
                cout<<"3)L' alabarda commissionatagli dalla guarnigione locale"<<endl;
                cout<<"----------"<<endl;
                cout<<"4)La spada bastarda tenuta da generazioni"<<endl;
                cin>>choice;

                    switch(choice){
                        case 1:{
                            //cout<<R"()"<<endl; COPIA E INCOLLA
                            cout<<R"(dopo aver preso il suo martello realizzasti che era pesante,ti sei allenato con esso finche' la tua costituzione non lo fece pesare piu' di una piuma e hai iniziato il tuo lavoro.)"<<endl;
                            cout<<"-----"<<endl;
                            cout<<"Ottieni: Martello, +5 STR, +5 HP "<<endl;
                            cout<<"-----"<<endl;

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
                                cout<<R"(dopo aver preso lo spadino e il boccolino ti sei allenato ad usare queste armi di destrezza finche' non eri pi� pi� lesto di Achille stesso, ti senti pronto per il tuo lavoro.)"<<endl;
                                cout<<"-----"<<endl;
                                cout<<"Ottieni: Spadino & Boccolino, giornea di cuoio, +10 DEX. "<<endl;
                                cout<<"-----"<<endl;

                                    app=G[pos].update_DEX(DEX_g,10);//aumenta di quanto inserisco
                                    G[pos].set_DEX(app);
                                    oggetto* s=new spada("Spadino & Boccolino",0.5,"ferro","affilata");
                                    G[pos].aggiungi_oggetto(s);

                                    G[pos].stampa_inventario();
                                    G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                                    break;
                    }
                        case 3:{
                                cout<<R"(dopo aver preso l�alabarda realizzi che quest� arma e� al quanto ingombrante, la tua forza non � abbastanza per tenerla bene quindi ti alleni, ma non sei capace di essere lesto con un simile armamenti, in ogni caso sei pronto per il tuo lavoro.)"<<endl;
                                cout<<"-----"<<endl;
                                cout<<"Ottieni: Alabarda, giornea di cuoio, +10 STR, -10 DEX. "<<endl;
                                cout<<"-----"<<endl;

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
                                cout<<R"(dopo aver preso questa spada appartenente alla tua famiglia da generazioni sei riempito da un senso di orgoglio, non ti pesa nulla a tenerla, e' come se fosse fata proprio per te, sei travolto dalla vitalitA' lasciata a te dai tuoi antenati, sei pronto per il tuo lavoro.)"<<endl;
                                cout<<"-----"<<endl;
                                cout<<"Ottieni: Spada Bastarda, giornea di cuoio, +25HP. "<<endl;
                                cout<<"-----"<<endl;

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
                cout<<R"(ti sono offerti 3 lavori che puoi fare, un nobile ti desidera come guardia del corpo nel suo viaggio verso una grande citta�, la guarnigione locale vuole assumerti come guardia per non lasciare dei prigionieri fuggire e un cavaliere ti vuole come scudiero per la sua prossima avventura, decidi di�)"<<endl;

                cout<<"scegli :"<<endl;
                cout<<"----------"<<endl;
                cout<<"1)fare da guardia al nobile"<<endl;
                cout<<"----------"<<endl;
                cout<<"2)arruolarti della guarnigione locale"<<endl;
                cout<<"----------"<<endl;
                cout<<"3)diventa uno scudiero "<<endl;
                cout<<"----------"<<endl;
                cin>>choice;

                switch(choice){
                    case 1:{
                        cout<<R"(lavorare per il nobile, mentre viaggi con il nobile dei briganti fermano la vostra carovana, lo difendi lealmente ma vieni attaccato nel caos, il tuo tendone e stato tagliato rendendoti zoppo, il nobile e� fuggito e ti ha lasciato per morto, zoppichi a casa e ti prepari per un altro arduo giorno di lavoro)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: -10HP, -25DEX. "<<endl;
                        cout<<"-----"<<endl;

                        app=G[pos].updown_HP(HP_g,10);
                        G[pos].set_HP(app);
                        app=G[pos].updown_DEX(DEX_g,25);
                        G[pos].set_DEX(app);
                        G[pos].stampa_inventario();
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                    break;
                    }
                    case 2:{
                        cout<<R"(ti arruoli nella guarnigione locale, ti e� data una nuova corazza, fai da guardia alla cella di un criminale ben conosciuto, non dormi per prevenire alcun tentativo di fuga e vieni pagato un modesto stipendio, dopo questa esperienza realizzi che essere una guardia non e' per te, ti prepari per un altro lavoro domani)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: sacchetto di monete, corazza in maglia di ferro(-5 DEX) "<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

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
                        cout<<R"(diventare uno scudiero per un giorno, non molto succede e per la tua semplice assistenza vieni ripagato, saluti il cavaliere e ti prepari per un altro lavoro domani)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: sacchetto di monete, pozione di salute. "<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

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
                cout<<R"(continui a fare lavori dopo lavori e diventi un mercenario al quanto famoso, alcuni vanno bene, altri no, ma in ogni caso, sei vivo, decidi di prendere il giorno libero per mettere la tua vita in ordine quindi decidi di�)"<<endl;

                cout<<"scegli :"<<endl;
                cout<<"----------"<<endl;
                cout<<"1)spendere un po' di tempo con la tua famiglia"<<endl;
                cout<<"----------"<<endl;
                cout<<"2)allenarti per passare il tempo"<<endl;
                cout<<"----------"<<endl;

                app2=G[pos].CheckInventarioSacchetto(6);
                if(app2=="sacchetto di monete"){
                    cout<<"3)vai a fare compere per equipaggiamento migliore "<<endl;//(appare solo se hai borsa di monete) ricerca sequenziale che se torva il sacco di monete ti fa uscire la scelta
                }
                else cout<<"terza scelta non presente perche' non hai il sacchetto di monete"<<endl;
                cout<<"----------"<<endl;
                cin>>choice;

                switch(choice){
                    case 1:{
                        cout<<R"(spendi la tua giornata con la tua famiglia, ti diverti, ti rilassi, le ferite di battagli passate sono come svanite, sei pronto per un'altra giornata...)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: +25HP."<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

                        app=G[pos].update_HP(HP_g,25);
                        G[pos].set_HP(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        break;
                    }
                    case 2:{
                        cout<<R"(passi il tempo ad allenarti, ormai ti viene naturale, non puoi fare altro che passare fluidamente da una mossa alla altra, cosi continui e continui, e� tutto cio� che conosci ormai, ti senti pronto alle tue prossime avventure�)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: +10 ATK, +10 DEX."<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

                        app=G[pos].update_STR(STR_g,10);
                        G[pos].set_STR(app);
                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                        break;
                    }
                    case 3:{
                        cout<<R"(trovi una bellissima corazza in acciaio e decidi di comprarla, ti senti piu� pronto alle tue prossime avventure...)"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: corazza in acciaio"<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

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
                cout<<R"(senti di un famoso Dungeon nelle vicinanze e senti la necessita di andarci, magari troverai del tesoro nei suoi antichi corridoi, decidi di...)"<<endl;

                cout<<"scegli :"<<endl;
                cout<<"----------"<<endl;
                cout<<"1)correre li per essere il primo a trovare alcun tesoro"<<endl;
                cout<<"----------"<<endl;
                cout<<"2)preparati portando qualche oggetto curativo"<<endl;
                cout<<"----------"<<endl;
                cout<<"3)preparati allenandoti un po'"<<endl;
                cout<<"----------"<<endl;
                cin>>choice;

                switch(choice){
                    case 1:{
                        cout<<"-----"<<endl;
                        cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<endl;
                        cout<<"-----"<<endl;
                        cout<<"Ottieni: +10 DEX"<<endl;
                        cout<<"-----"<<endl;

                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);

                        break;
                    }
                    case 2:{

                        cout<<"-----"<<endl;
                        cout<<"Ottieni: pozione curativa."<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

                        oggetto* p=new pozione("pozione curativa",0.1,"vetro","curativo");
                        G[pos].aggiungi_oggetto(p);
                        G[pos].stampa_inventario();

                        cout<<"-----"<<endl;
                        cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<endl;
                        cout<<"-----"<<endl;
                        break;
                        }
                    case 3:{

                        cout<<"-----"<<endl;
                        cout<<"Ottieni: +10 ad ogni statistica."<<endl;//trova scopo sacchetto monete
                        cout<<"-----"<<endl;

                        app=G[pos].update_STR(STR_g,10);
                        G[pos].set_STR(app);
                        app=G[pos].update_DEX(DEX_g,10);
                        G[pos].set_DEX(app);
                        app=G[pos].update_HP(HP_g,10);
                        G[pos].set_HP(app);
                        app=G[pos].update_MP(MP_g,10);
                        G[pos].set_MP(app);
                        G[pos].stampa_character(DEX_g,STR_g,HP_g,MP_g);
                        cout<<"-----"<<endl;
                        cout<<"ti ritrovi davanti al Dudgeon, la tua avventura inizia"<<endl;
                        cout<<"-----"<<endl;
                        break;
                    }
                }

        break;//del case 3 sopra
        }
        case 4:{
            cout<<"---storia Avventuriero---"<<endl;
            //storia
            break;
        }
        case 5:{
            cout<<"---storia Carabiniere---"<<endl;
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
        int pos=1;
        int sop=pos-1;//lo uso per riferirmi al giocatore 1
        cout<<"Comincia Il Combattimento"<<endl;
        cout<<G[sop].get_DEX()<<endl;//la destrezza rimani cosi com'� non viene modificata
        cout<<G[pos].get_DEX()<<endl;//perche al giocatore 2 ci sono valori sfasati? dovevamo mettere uno al posto di 2 nella funzione p.Gioco(1) dell int main
        //cout<<G[pos].get_STR()<<endl; per testare se era tutto ok

            if(G[sop].get_DEX()>G[pos].get_DEX()){//INIZIA CHI HA PIU DESTREZZA
                cout<<"inizia G1"<<endl;
            }
            else{
                cout<<"inizia G2"<<endl;
            }



    }





};


#endif // HEADER_H_INCLUDED
