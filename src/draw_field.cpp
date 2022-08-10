void draw_stock(SDL_Texture *BackFound,int fh){
    if(fh<1){
        draw_found(BackFound,vec2_i(100,50),vec2_i(72,96));
        return;
    }
    for(int i=0;i<fh;i++){
        draw_back(BackFound,vec2_i(100-(i*3),50-(i*2)),vec2_i(72,96));
    }
}

void draw_waste(SDL_Texture *kaards,SDL_Texture *BackFound,card kaard){
    if(kaard.suit==""){
        draw_found(BackFound,vec2_i(182,50),vec2_i(72,96));
        return;
    }
    kaard.pos.x=182;
    kaard.pos.y=50;
    draw_card(kaards,kaard);
}

void draw_foundation(SDL_Texture *kaards,SDL_Texture *BackFound,deck found){
    int i=3;
    for (card kaard : found.c){
    
    if(kaard.suit==""){
        draw_found(BackFound,vec2_i(100+(82*i),50),vec2_i(72,96));
        i++;
        continue;
    }
    kaard.pos.x=100+(82*i);
    kaard.pos.y=50;
    draw_card(kaards,kaard);
    i++;
    }
}

void draw_tabeleau(SDL_Texture *kaards,SDL_Texture *BackFound,deck tableau[7],int hidden[7]){
    for(int i=0;i<7;i++){
        int j=0;
        for(card kaard : tableau[i].c){
            kaard.pos.x=100+(82*i);
            kaard.pos.y=196+(j*10);
            if(j<hidden[i]){
                draw_back(BackFound,vec2_i(kaard.pos.x,kaard.pos.y),vec2_i(72,96));
            }else{
                draw_card(kaards,kaard);
            }
            
            j++;
        }
    }
}

void draw_field(SDL_Texture *kaards,SDL_Texture *BackFound){
    draw_stock(BackFound,field.stock.c.size()/3);
    draw_waste(kaards,BackFound,field.waste.c.back());
    
    deck found;

    found.c.push_back(field.foundation[0].c.back());
    found.c.push_back(field.foundation[0].c.back());
    found.c.push_back(field.foundation[0].c.back());
    found.c.push_back(field.foundation[0].c.back());

    draw_foundation(kaards,BackFound,found);
    draw_tabeleau(kaards,BackFound,field.tableau,field.hidden);
}