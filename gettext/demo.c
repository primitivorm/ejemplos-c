/*
 * Add to environment variable LIBRARY
 * C:\gcc\i686-w64-mingw32\includ*
 * */

#include"libintl.h"
#include<dlfcn.h>
#include<locale.h>
#include<stdio.h>

#define _(String) gettext (String)

int main()
{
    setlocale(LC_ALL,"");
    bindtextdomain("helloworld","/usr/share/locale");
    textdomain("helloworld");
    printf(_("Hello World\n"));
    return 0;
}
