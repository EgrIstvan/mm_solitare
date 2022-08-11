bool test_coll(aabb a, vec2_int v){
    if(a.b.x<v.x&&a.e.x>v.x&&a.b.y<v.y&&a.e.y>v.y)
        return true;
    return false;
}
bool canKlik=true;
void mouse_in(){
    vec2_int pos=vec2_int(0,0);
    Uint32 buttons;

    

    SDL_PumpEvents();  // make sure we have the latest mouse state.

    buttons = SDL_GetMouseState(&pos.x, &pos.y);
    if (((buttons != SDL_BUTTON_LMASK))){
        canKlik=true;
    }
    if(test_coll(field_coll.stock,pos)){
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
        if ((buttons == SDL_BUTTON_LMASK)&&canKlik){
            if(field.stock.c.size()==0){
                field.waste.c.erase(field.waste.c.begin());
                for(card kaard : field.waste.c)
                    field.stock.c.insert(field.stock.c.cbegin(),kaard);
                
                field.waste.c.erase(field.waste.c.begin(),field.waste.c.end());
                card nullcard={
                    "",
                    0,
                    vec2_i(0,0)
                };

                field.waste.c.push_back(nullcard);

            }else{
                field.waste.c.push_back(field.stock.c.back());
                field.stock.c.pop_back();
            }
            canKlik=false;
        }
    }else{
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }
    
}