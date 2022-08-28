bool test_coll(aabb a, vec2_int v){
    if(a.b.x<v.x&&a.e.x>v.x&&a.b.y<v.y&&a.e.y>v.y)
        return true;
    return false;
}

int test_all(aabb a[],vec2_int v,int s){
    
    for(int i=0;i<s;i++){
        if(test_coll(a[i],v))
            return i;
    }
    return -1;
}

std::array<int, 2> test_all_t(std::vector<aabb> a[],vec2_int v,int s){
    
    for(int i=0;i<s;i++){
        int j=0;
        std::reverse(a[i].begin(),a[i].end());
        for(aabb box : a[i]){
            if(test_coll(box,v)){
                return {i,j};
            }
            j++;
        }
    }
    return {-1,0};
}

std::string get_color_suit(std::string suit){
    if(suit=="clubs"||suit=="spades")
        return "black";
    else
        return "red";
}

void delete_card(int i){
    if(i==0){
        field.waste.c.pop_back();
    }else if(0<i&&i<5){
        field.foundation[i-1].c.pop_back();
    }else if(4<i&&i<12){
        field.tableau[i-5].c.pop_back();
    }
}

void delete_all(int i,int q){
    for(int j=0;j<q;j++){
        if(i==0){
            field.waste.c.pop_back();
        }else if(0<i&&i<5){
            field.foundation[i-1].c.pop_back();
        }else if(4<i&&i<12){
            field.tableau[i-5].c.pop_back();
        }
    }
}



int del=-1;
int quan=1;
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
    }else if(test_coll(field_coll.waste,pos)){
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
        if((buttons == SDL_BUTTON_LMASK)&&canKlik){
        if(holding.c.back().val==0&&field.waste.c.back().val!=0){
            holding.c.erase(holding.c.begin(),holding.c.end());
            holding.c.push_back(field.waste.c.back());
            del=0;
        }
        canKlik=false;
        }
    }else{
        int test_foundation = test_all(field_coll.foundation,pos,4);
        std::array<int, 2> test_tableau = test_all_t(field_coll.tableau,pos,7);
        
        //std::cout<<canKlik<<"\n";
        if(test_foundation>-1){
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if((buttons == SDL_BUTTON_LMASK)&&canKlik){
            if(holding.c.back().val!=0&&field.foundation[test_foundation].c.back().val+1==holding.c.back().val){
                if(field.foundation[test_foundation].c.back().val!=0){
                    if(holding.c.back().suit==field.foundation[test_foundation].c.back().suit){
                        field.foundation[test_foundation].c.push_back(holding.c.back());
                        delete_card(del);
                        card nullcard={
                            "",
                            0,
                            vec2_i(0,0)
                        };
                        del=-1;
                        holding.c.erase(holding.c.begin(),holding.c.end());
                        holding.c.push_back(nullcard);
                    }else{
                    card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                    holding.c.erase(holding.c.begin(),holding.c.end());
                    holding.c.push_back(nullcard);
                    }
                }else{
                    field.foundation[test_foundation].c.push_back(holding.c.back());
                    delete_card(del);
                    card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                    del=-1;
                    holding.c.erase(holding.c.begin(),holding.c.end());
                    holding.c.push_back(nullcard);
                }
                
            }else if(holding.c.back().val==0&&field.foundation[test_foundation].c.back().val!=0){
                holding.c.erase(holding.c.begin(),holding.c.end());
                holding.c.push_back(field.foundation[test_foundation].c.back());
                
                del=1+test_foundation;
            }else{
                card nullcard={
                    "",
                    0,
                    vec2_i(0,0)
                };
                holding.c.erase(holding.c.begin(),holding.c.end());
                holding.c.push_back(nullcard);
            }
            canKlik=false;
            }
        }else if(test_tableau[0]>-1){
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if((buttons == SDL_BUTTON_LMASK)&&canKlik){
            if(field.tableau[test_tableau[0]].c.empty()){
                if(holding.c.front().val==13){
                    for(card kaard : holding.c){
                        field.tableau[test_tableau[0]].c.push_back(kaard);
                    }
                    
                    delete_all(del,quan);
                    quan=1;
                    card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                    holding.c.erase(holding.c.begin(),holding.c.end());
                    holding.c.push_back(nullcard);
                }else{
                    card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                    holding.c.erase(holding.c.begin(),holding.c.end());
                    holding.c.push_back(nullcard);
                }
            }else if(holding.c.back().val!=0&&field.tableau[test_tableau[0]].c.back().val-1==holding.c.front().val){
                if(get_color_suit(holding.c.front().suit)!=get_color_suit(field.tableau[test_tableau[0]].c.back().suit)){
                    for(card kaard : holding.c){
                        field.tableau[test_tableau[0]].c.push_back(kaard);
                    }
                    
                    delete_all(del,quan);
                    quan=1;
                    card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                    holding.c.erase(holding.c.begin(),holding.c.end());
                    holding.c.push_back(nullcard);
                }else{
                card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                holding.c.erase(holding.c.begin(),holding.c.end());
                holding.c.push_back(nullcard);
                }
            }else if(holding.c.back().val==0&&field.tableau[test_tableau[0]].c.back().val!=0){
                holding.c.erase(holding.c.begin(),holding.c.end());
                for(int i=0;i<test_tableau[1]+1;i++){
                    std::cout<<test_tableau[1];
                    holding.c.insert(holding.c.begin(),field.tableau[test_tableau[0]].c.at(field.tableau[test_tableau[0]].c.size()-(i+1)));
                }
                del=5+test_tableau[0];
                quan=test_tableau[1]+1;
            }else{
                card nullcard={
                        "",
                        0,
                        vec2_i(0,0)
                    };
                holding.c.erase(holding.c.begin(),holding.c.end());
                holding.c.push_back(nullcard);
            }
            //std::cout<<test_tableau[1];
            canKlik=false;
            }
        }else{
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        }
    }
}