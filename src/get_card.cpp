void get_card(card &kaard){
    std::map<std::string,int> suits;
    suits["clubs"]=0;
    suits["spades"]=1;
    suits["hearts"]=2;
    suits["diamonds"]=3;

    kaard.pos_t.y=1+(98*suits[kaard.suit]);
    kaard.pos_t.x=1+73*(kaard.val-1);

    return;
}