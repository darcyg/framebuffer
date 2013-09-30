#include "color.h"

int main(void){
    rgb r;
    std::cout <<"color:"<<r.toString()<<std::endl;
    rgb grey(125,125,125);
    std::cout <<"color:"<<grey.toString()<<std::endl;
    rgb rouge;
    rouge.RED();
    std::cout <<"rouge:"<<rouge.toString()<<std::endl;
    std::cout <<"test:"<<rouge.red()<<std::endl;

}
