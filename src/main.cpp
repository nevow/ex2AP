#include "managment/MainFlow.h"

int main() {
    MainFlow *mf = new MainFlow();
    mf->initialize();
    mf->input();
    delete (mf);
    return 0;
}