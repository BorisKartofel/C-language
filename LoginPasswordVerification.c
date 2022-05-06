 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>

 int main(){

    char correct_login[6]  = "login";       //Could be replaced by any other login
    char correct_password[9]  = "password";      //Could be replaced by any other password
    char login[9];      //Could be changed for any other array size
    char password[9];       //Could be changed for any other array size
    int are_logins_equals;      //Declare variable for strings comparison below
    int are_passwords_equals;      //Declare variable for strings comparison below

    for(int unsuccessful_attempts = 0; unsuccessful_attempts < 5; ){
             
        printf("Enter Login: \n");
        scanf("%s", login);
        printf("Enter Password: \n");
        scanf("%s", password);

        are_logins_equals = strcmp(login, correct_login);
        are_passwords_equals = strcmp(password, correct_password);

        if( (are_logins_equals != 0) && (are_passwords_equals != 0) ) {
            unsuccessful_attempts++;
            printf("User with such credentials was not found\n");       
            if(unsuccessful_attempts == 3){
                printf("Waiting 3 secs ...\n");
                printf("---\n");                 
                if(1) sleep(3);     //For some reason sleep() executs before printf, so I decided to cover it with 'if' statement 
            }
            if(unsuccessful_attempts == 5){
                printf("Exit 0\n"); 
            }
        }   
        else {
            printf("Welcome ADMIN!\n");
            unsuccessful_attempts = 5;
        }

    }

 return 0;
 }