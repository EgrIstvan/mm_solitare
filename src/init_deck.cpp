void init_deck(){
    srand (time(NULL));
    deck main;

    std::map<int,std::string> suits;
    suits[0]="clubs";
    suits[1]="spades";
    suits[2]="hearts";
    suits[3]="diamonds";

    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
        card kaard={
            suits[i],
            j,
            vec2_i(0,0)
        };
        main.c.push_back(kaard);
        }
    }

    for(int i=0;i<1024;i++){
        std::swap(main.c[rand()%52],main.c[rand()%52]);
    }

    for(int i=0;i<7;i++){
        for(int j=1;j<i+2;j++){
            field.tableau[i].c.push_back(main.c.back());main.c.pop_back();
            field.hidden[i]=i;
        } 
    }

    field.stock = main;

    card nullcard={
        "",
        0,
        vec2_i(0,0)
    };

    holding.c.push_back(nullcard);

    field.waste.c.push_back(nullcard);

    field.foundation[0].c.push_back(nullcard);
    field.foundation[1].c.push_back(nullcard);
    field.foundation[2].c.push_back(nullcard);
    field.foundation[3].c.push_back(nullcard);
}