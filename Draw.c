#include <stdio.h>
#include <string.h>

int main(int argc, char *str[]) {
    if (argc == 2){
        if (!strcmp(str[1], "--help")){
            printf ("-a ==> prints an Animal\n-h ==> prints a Human\n-c ==> prints a Car\n");
        }

        else if (!strcmp(str[1], "-a")){
            puts (" ,;;:;,");
            puts ("   ;;;;;");
            puts ("  ,:;;:;    ,'=.");
            puts ("  ;:;:;' .=\" ,'_\\");
            puts ("  ':;:;,/  ,__:=@");
            puts ("   ';;:;  =./)_");
            puts ("     `\"=\\_  )_\"`");
            puts ("          ``'\"`");
        }

    //    else if (!strcmp(str, "-h"))

    //    else if (!strcmp(str, "-c"))
        
    }

    else printf("Undefined Expression\n");
    return 0;
}


/*



      ,-"=-.
     .       \
     "='"=\   '
     `@] @'|   )
     ) ` ' ),-`
      \^_,  \,  
        ,(\,/ )`-.



        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");
        puts ("");



*/