#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// define struct of type Elementary_PLAYER
struct PLAYER
{
    char   player_name[20];
    struct PLAYER* Next;
};

// define the struct of Type Queue_Players

struct Queue_Players
{

    char player_name[20];
    struct Queue_Players* Next;
    // Implement the queue using the linked list
};
//pointers to the front and rear for each queue of the competitive teams
//set their initial value to null and change it at every enqueue or dequeue operation
struct Queue_Players* front1=NULL;
struct Queue_Players* front2=NULL;
struct Queue_Players* rear1=NULL;
struct Queue_Players* rear2=NULL;

//define struct of type TEAM
struct TEAM
{
    char name[20];
    char code[10];
    int num_of_wins;
    int num_of_draws;
    int num_of_loses;
    int goals_difference;
    int points;
    struct PLAYER* elemantary;//pointer to the head of the linked list of elementary players
    struct Queue_Players* spare;//pointer to the front in the Queue of the spare players
    struct TEAM* Next;//Link field

};
struct TEAM *T,*p;//global variables of type TEAM

// declaration of the constraining linked Lists functions
struct TEAM* MakeEmpty(struct TEAM* T);
void DeleteList(struct TEAM* T);
void Insert(char name[],char code[],int num_of_wins,int num_of_draws,int num_of_loses,int goals_diff);
void printList();
int IsLast(struct TEAM * T1);
int IsEmpty();
struct PLAYER* MakeEmptyPlayer(struct PLAYER* p1);
void size();//this function to tell the user the number of teams in each adding or deleting a team

////////////////////////////////////////
//declaration of my own functions
void ReadFile();
void calculate_points();
void Add_Team();
void Modify_Team();
struct TEAM* FindCode(char code1[10]);
void Delete_Team();
struct TEAM* FindPreviousTeam(char code[10]);
void create_match();
void storePlayers(struct TEAM* T1,struct TEAM* T2);
void Insert_player(char name[20],struct TEAM* t);
struct PLAYER* FindPreviousPlayer(char name[20],struct PLAYER* head);
void DeletePlayer(char name [20],struct PLAYER* p1);
void print_Players(struct PLAYER* p1);
int  IsLastPlayer(struct PLAYER* p,struct PLAYER* p1);
struct PLAYER* MakeEmptyPlayer(struct PLAYER* p1);
void DeletePLAYERList(struct PLAYER* p);
void inner_menu(T1,T2);
void redCard(struct TEAM* T1,struct TEAM* T2);
void savePlayersInFile(struct TEAM* T1,struct TEAM* T2);
void Enqueue1(char name1[20],struct TEAM* T1);
void Enqueue2(char name1[20],struct TEAM* T2);
void dequeue1(struct TEAM* T1);
void dequeue2(struct TEAM* T2);
void elementaryToSpare(struct TEAM* T1,struct TEAM* T2);
///////////////////////////////////////
struct TEAM* MakeEmpty(struct TEAM* T)
{

    if(T !=NULL)
        DeleteList(T);

    T=(struct TEAM*)malloc(sizeof(struct TEAM));

    if(T==NULL)
        printf("Out of memory ! \n");
    T->Next=NULL;
    return T;
}
struct PLAYER* MakeEmptyPlayer(struct PLAYER* p1)
{

    if(p1 !=NULL)
        DeletePLAYERList(p1);

    p1=(struct PLAYER*)malloc(sizeof(struct PLAYER));

    if(p1==NULL)
        printf("Out of memory ! \n");
    p1->Next=NULL;
    return p1;
}

void DeleteList(struct TEAM *T)
{

    struct TEAM *p,*temp;
    p=T->Next;
    T->Next=NULL;
    while(p!=NULL)
    {
        temp=p->Next;
        free(p);
        p=temp;
    }
}
void DeletePLAYERList(struct PLAYER *p1)
{
    struct PLAYER *p,*temp;
    p=p1->Next;
    p1->Next=NULL;
    while(p!=NULL)
    {
        temp=p->Next;
        free(p);
        p=temp;
    }
}

void Insert(char name[20],char code[10],int num_of_wins,int num_of_draws,int num_of_loses,int goals_diff)
{
    //this function to insert a new team
    struct TEAM *temp,*p1;
    temp=(struct TEAM*)malloc(sizeof(struct TEAM));

    if(temp==NULL)
    {
        printf("Out of space \n");
    }
    else
    {
        strcpy(temp->name,name);
        strcpy(temp->code,code);
        temp->num_of_wins=num_of_wins;
        temp->num_of_loses=num_of_loses;
        temp->num_of_draws=num_of_draws;
        temp->goals_difference=goals_diff;
        if(T==NULL)
        {
            T=temp;
        }
        else
        {
            p1=T;
            T=temp;
            temp->Next=p1;
        }
    }
}
void printList()
{

    struct TEAM *T1=T;

    if(IsEmpty(T1))
    {
        printf("The LinkedList is empty !\n");
    }
    else
    {
        do
        {
            printf("%s\t ",T1->name);
            printf("%s\t",T1->code);
            printf("%d\t",T1->num_of_wins);
            printf("%d\t",T1->num_of_draws);
            printf("%d\t",T1->num_of_loses);
            printf("%d\t",T1->goals_difference);
            printf("%d\t",T1->points);
            printf("\n");
            T1=T1->Next;//T1 is point to the next team to print
        }
        while(!IsLast(T1));
        printf("\n");
    }

}
int IsLast(struct TEAM * T1)
{

    return T1->Next==NULL;
}
int IsLastPlayer(struct PLAYER* p,struct PLAYER* p1)
{

    return p->Next==NULL;
}
int IsEmpty()
{
    return T->Next==NULL;

}
int IsEmptyPLAYER(struct PLAYER *p1 )
{
   // check whether the elementary players list is empty or not
    return p1->Next==NULL;
}
int main()
{
    printf("\n welcome in FIFA 2022 ! \n");
    // display the menu of choices
    int x;
    printf("select your choice :\n");
    printf("\n 1-Read the File that contains the information of teams \n");
    printf("\n 2-Calculate the points for each team \n");
    printf("\n 3-Sort the teams \n");
    printf("\n 4-Add Team \n");
    printf("\n 5-Modify Team \n");
    printf("\n 6-Delete Team \n");
    printf("\n 7-Print Teams with their relevant information \n");
    printf("\n 8-Create a match\n");
    printf("\n 9-Save back the teams information in teamsInfo File \n");
    printf("\n 10-Exit \n");

    scanf("%d",&x);
    while(x!=10)
    {

        if(x==1)
        {
            T=MakeEmpty(NULL);
            ReadFile();
        }
        if(x==2)
        {
            calculate_points();
        }
        if(x==3){
           //sortting();
           printf("RadixSort()");
        }
        else if(x==4)
        {
            Add_Team();
        }
        else if(x==5)
        {
            Modify_Team();
        }
        else if(x==6)
        {
            Delete_Team();
        }
        else if(x==7)
        {
            printf("\n The teams are : \n");
            printf("name    code   wins   draws   loses   goal_Differences \n");
            printList();
            printf("We came back from the printing\n");
        }
        else if(x==8)
        {
            create_match();
        }
        else if(x==9)
        {

            saveTeamsInFile();
        }

        printf("\n select your choice :\n");
        printf("\n 1-Read the File that contains the information of teams \n");
        printf("\n 2-Calculate the points for each team \n");
        printf("\n 3-Sort the teams \n");
        printf("\n 4-Add Team \n");
        printf("\n 5-Modify Team \n");
        printf("\n 6-Delete Team \n");
        printf("\n 7-Print Teams with their relevant information \n");
        printf("\n 8-create a match \n");
        printf("\n 9-Save back the teams information in teamsInfo File \n");
        printf("\n 10-Exit \n");
        scanf("%d",&x);
    }
    return 0;
}
void ReadFile()
{

    FILE* fptr;
    fptr=fopen("teams.txt","r");//open the file in read mode
    if(fptr==NULL)
    {
        // check whether the File is exist  or not
        printf("Sorry !The File is not exist ! \n");
    }
    else
    {
        const char s[1] = ",";// separate the information of each team via to (,) character
        char code1[10];//to store the code of the current team
        char name1[20]; //to store the name of the current team
        char token[100]; //temporary array of character to store the data we will insert in each iteration
        char line[40]; // to store the whole line we read from the file
        int wins,draws,loses,goal_diff;
        while(fgets(line,sizeof line,fptr)!=NULL)
        {
            strcpy(token,strtok(line,s));//store the first capture when split via (,) in token variable
            for(int i=0; i<6; i++)
            {
                // six iteration because each team has six information parts as shown:
                if(i==0)
                {
                    // this iteration to store the name of team from token to name1
                    strcpy(name1,token);
                    strcpy(token,strtok(NULL,s));
                }
                else if(i==1)
                {
                    // this iteration to store the code of team from token to code1
                    strcpy(code1,token);
                    strcpy(token,strtok(NULL,s));
                }
                else if(i==2)
                {
                    // this iteration to store the number of wins of team from token to wins
                    wins=atoi(token);
                    strcpy(token, strtok(NULL,s));
                }
                else if(i==3)
                {
                    // this iteration to store the number of draws of team from token to draws
                    draws=atoi(token);
                    strcpy(token, strtok(NULL,s));
                }
                else if(i==4)
                {
                    // this iteration to store the number of loses of team from token to loses
                    loses=atoi(token);
                    strcpy(token, strtok(NULL,s));
                }
                else if(i==5)
                {
                    // this iteration to store the number of goal differences of team from token to wins
                    goal_diff=atoi(token);
                }

            }
            // here we will insert the nodes in the linked list
            Insert(name1,code1,wins,draws,loses,goal_diff);
        }
        fclose(fptr);
    }
}
void size()
{
    struct TEAM *p1;
    p1=T->Next;
    int counter=0;
    while(p1!=NULL)
    {
        counter++;
        p1= p1->Next;
    }
    printf("you have now %d teams\n",counter);
}

// This function is to calculate the total points of each team
void calculate_points()
{

    struct TEAM* p1;
    p1=T;
    while(p1->Next!=NULL)
    {
      // implement the calculating point equation
        p1->points=(3*p1->num_of_wins)+(p1->num_of_draws);
        printf("The points of team %s = %d \n",p1->name,p1->points);
        p1=p1->Next;
    }

}

// this function to add a team into the linked list
void Add_Team()
{
    struct TEAM* tocheckname;
    char name1[20];
    char code1[10];
    int wins,draws,loses,goal_differences;
    printf("To add a new team enter the following :\n");
    printf("Team name : \n");
    scanf("%s",&name1);
    printf("Team Code : \n");
    scanf("%s",&code1);
    printf("Number of wins :\n");
    scanf("%d",&wins);
    printf("Number of draws :\n");
    scanf("%d",&draws);
    printf("Number of loses :\n");
    scanf("%d",&loses);
    printf("Number of goal differences :\n");
    scanf("%d",&goal_differences);
    // Insert the user's data to create a new team into the linked list
    Insert(name1,code1,wins,draws,loses,goal_differences);
    // print the new number of total teams to make check that we actually add it
    size();
}

void Modify_Team()
{
    struct TEAM*p1;
    char code1[10];
    char name1[20];
    int wins,draws,loses,goal_dif;
    printf("Enter the code of the team that you want to modify : \n");
    scanf("%s",&code1);
    p1=FindCode(code1);
    if(strcmp(p1->code,code1)==0)
    {
        printf("Enter the modified data respectively as shown : \n");
        printf("Name,Code,wins,draws,loses,goal_dif\n");
        scanf("%s",&name1);
        scanf("%s",&code1);
        scanf("%d",&wins);
        scanf("%d",&draws);
        scanf("%d",&loses);
        scanf("%d",&goal_dif);
        // Apply the new Information to the wanted team
        strcpy(p1->name,name1);
        strcpy(p1->code,code1);
        p1->num_of_wins=wins;
        p1->num_of_draws=draws;
        p1->num_of_loses=loses;
        p1->goals_difference=goal_dif;
    }
    else
    {
        // If the user want to modify non existing team
        printf("\n This Code is not available !\n");
    }
}
// The following function is to return a pointer to the team that we want to modify or delete it
// also we will use this function for many times when we create matches
struct TEAM* FindCode(char code1[10])
{
    struct TEAM* p1;
    p1=T;
    while(p1->Next!=NULL && strcmp(p1->code,code1)!=0)
    {
        p1=p1->Next;
    }
    return p1;
}
void Delete_Team()
{

    char search_code[10];
    printf("Enter the code of the team you want to delete it :\n");
    scanf("%s",&search_code);
    struct TEAM* p, *temp;
    p=FindPreviousTeam(search_code);// to point to the specified team that the user want to delete

    if(!IsLast(p))
    {
        temp=p->Next; //temp now is  the node we will delete it
        p->Next=temp->Next;// to make check that we won't lose the linked list in the memory
        free(temp);// Delete the required team
    }

}

struct TEAM* FindPreviousTeam(char search_code[10])
{
    // this function will return a pointer to the previous team of the team that will be deleted
    struct TEAM *p;
    p=T;

    while(p->Next !=NULL && strcmp((p->Next->code),search_code) != 0)
    {
        p=p->Next;
    }
    return p;
};

void saveTeamsInFile()
{

    struct TEAM* T1;
    T1=T->Next;
    FILE* fptr;
    fptr=fopen("teamsInfo.txt","w");// Open the File in writing mode
    while(T1->Next!=NULL)
    {

        fprintf(fptr,"Team name :%s\n",T1->name);
        fprintf(fptr,"Team code :%s\n",T1->code);
        fprintf(fptr,"number of wins :%d\n",T1->num_of_wins);
        fprintf(fptr,"number of draws :%d\n",T1->num_of_draws);
        fprintf(fptr,"number of loses:%d\n",T1->num_of_loses);
        fprintf(fptr,"number of goals differences :%d\n",T1->goals_difference);
        fprintf(fptr,"Total Points :%d\n",T1->points);
        fprintf(fptr,"--------------------------------------------->\n");
        T1=T1->Next;
    }
    fclose(fptr);

}

void sortting(){

 for(struct TEAM* n1=T->Next;n1!=NULL;n1=n1->Next){

    for(struct TEAM* n2=n1;n2->Next!=NULL;n2=n2->Next){

        if((n2->points) < (n1->points)){
          struct TEAM* temp=(struct TEAM*)malloc(sizeof(struct TEAM));
            temp->Next=n2->Next;
            n2->Next=n1;
            n1->Next=temp->Next;
        }
        else if(n2->points==n1->points){
            if(n2->goals_difference>n1->goals_difference){
            struct TEAM* temp=(struct TEAM*)malloc(sizeof(struct TEAM));
            temp->Next=n2->Next;
            n2->Next=n1;
            n1->Next=temp->Next;
            }
        }

        /////
    }
 }
printf("The sorted list is :\n");
  printList();
}

//// Function of phase Two

void create_match()
{
    /* these two arrays of character will help us to get pointers to the two teams in the match
    by sending them to FindCode function
    */
    char code1[10];
    char code2[10];

    int x;
    struct TEAM*T1,*T2;
    printf("Enter the code of the first team \n");
    scanf("%s",&code1);
    T1=FindCode(code1);//get pointer to first competitive team
    if(strcmp(T1->code,code1)!=0)//check whether this team is really exist
    {
        printf("Sorry This team is not exist ! \n");
    }
    else
    {
        printf("Enter the code of the second team \n");
        scanf("%s",&code2);
        T2=FindCode(code2);
        if(strcmp(T2->code,code2)!=0)
        {
            printf("Sorry this team is not exist\n");
        }
        else if(strcmp(T1->code,T2->code)==0)
        {
            // If the user enter the same code for two teams
            printf("The one team can not play with it self\n");
        }
        else
        {
            printf("The match is between %s and %s \n",T1->name,T2->name);

        }

        storePlayers(T1,T2);
        inner_menu(T1,T2);// the inner menu inside each match
    }
}

void storePlayers(struct TEAM*T1,struct TEAM* T2)
{

    FILE* fptr;
    fptr=fopen("players.txt","r");
    struct TEAM* t1;
    char code[30];
    char readedData[30];
    char name[20];
    T1->elemantary=MakeEmptyPlayer(NULL);
    T2->elemantary=MakeEmptyPlayer(NULL);
    if(fptr==NULL)
        printf("The file is not exist \n");
    else
    {
        while(fgets(readedData,30,fptr)!=NULL)
        {
            if(readedData[0]=='*')
            {
                code[0]=readedData[1];
                code[1]=readedData[2];
                code[2]=readedData[3];
            }
            else
            {
                t1=FindCode(code);
                strcpy(name,strtok(readedData,"-"));
                if(atoi(name)<=11)
                {
                    //insert elementary Player
                    strcpy(name,strtok(NULL,"-"));
                    if(strcmp(t1->name,T1->name)==0)
                        Insert_player(name,T1);
                    else if(strcmp(t1->name,T2->name)==0)
                        Insert_player(name,T2);
                }
                else
                {
                    strcpy(name,strtok(NULL,"-"));
                    if(strcmp(t1->name,T1->name)==0)
                        Enqueue1(name,T1);
                    else if(strcmp(t1->name,T2->name)==0)
                        Enqueue2(name,T2);
                }
            }
        }
    }
    fclose(fptr);
}


void Insert_player(char line[20],struct TEAM* t)
{

    struct PLAYER *temp,*p1;
    temp=(struct PLAYER*)malloc(sizeof(struct PLAYER));

    if(temp==NULL)
    {
        printf("Out of space \n");
    }
    else
    {
        strcpy(temp->player_name,line);
        if(t->elemantary==NULL)
        {
            t->elemantary=temp;
        }
        else
        {
            p1=t->elemantary;
            t->elemantary=temp;
            temp->Next=p1;
        }
    }

}
void print_Players(struct PLAYER* p)
{

    while(p->Next!=NULL)
    {
        printf("%s\n",p->player_name);
        p=p->Next;
    }
}

void inner_menu(struct TEAM* T1,struct TEAM* T2)
{

    int x;
    printf("\n \n ! Best of luck for each team !\n let we start\n");
    printf("select the number of your choice \n");
    printf("1-give red card for a player\n");
    printf("2-swap an elementary player to a spare player\n");
    printf("3-save the information about the players in a file\n");
    printf("4-print the list of the elementary players for a specific team\n");
    printf("5-Back to the primary menu\n");
    scanf("%d",&x);
    while(x!=5)
    {
        if(x==1)
        {
            redCard(T1,T2);

        }
        else if(x==2)
        {
            elementaryToSpare(T1,T2);
        }
        else if(x==3)
        {

            savePlayersInFile(T1,T2);
        }
        else if(x==4)
        {

            struct TEAM* t;
            char code1[20];
            printf("   Enter the code of the team that you want to print its elementary players\n");
            printf("\n dear user make sure that your chosen team is in the match\n");
            scanf("%s",&code1);
            t=FindCode(code1);
            printf("%s elementary players are:\n",t->name);
            print_Players(t->elemantary);

        }

        printf("select the number of your choice \n");
        printf("1-give red card for a player\n");
        printf("2-swap an elementary player to a spare player\n");
        printf("3-save the information about the players in a file\n");
        printf("4-print the list of the elementary players for a specific team\n");
        printf("5-Back to the primary menu\n");
        scanf("%d",&x);
    }

}


void redCard(struct TEAM* T1,struct TEAM* T2)
{

    char code1[10];
    char name1[20];
    struct TEAM* t;
    printf("Enter the code of the team which include the player that you want to delete\n");
    scanf("%s",&code1);
    t=FindCode(code1);
    if(strcmp(t->code,T1->code)!=0 && strcmp(t->code,T2->code)!=0)
    {
        printf("This team is not in the match\n");
        printf("You can check your Information and try again !\n");
    }
    printf("we will delete the player of team %s\n",t->name);
    if(strcmp(t->code,T1->code)==0)
    {
        // if the pointer points to the first team then delete the player of T1
        printf("Enter the name of the player to give him the red card \n");
        scanf("%s",&name1);
        //send the name of the player to be deleted from it's correct team
        DeletePlayer(name1,T1->elemantary);
    }
    if(strcmp(t->code,T2->code)==0)
    {
         // if the pointer points to the second team then delete the player of T2
        printf("Enter the name of the player to give him the red card \n");
        scanf("%s",&name1);
        DeletePlayer(name1,T2->elemantary);
    }

}
void DeletePlayer(char name1[20],struct PLAYER* p1)
{

    struct PLAYER* p2,*temp;
    printf("The player who will go out side is %s :\n",name1);
    printf("So the elementary players list will be:\n");// print the new list after deleting
    char name2[20];
    strcpy(name2,strcat(name1,"\n"));

    p2=FindPreviousPlayer(name2,p1);

    if(!IsLastPlayer(p2,p1))
    {
        temp=p2->Next;
        p2->Next=temp->Next;
        free(temp);
    }
    print_Players(p1);// print the new list after deleting

}

struct PLAYER* FindPreviousPlayer(char name2[20],struct PLAYER* p1)
{
// this function will be used when want to delete a player as we did in deleting team
    struct PLAYER* p2;
    p2=p1;
    while(p2->Next!=NULL && strcmp(p2->Next->player_name,name2)!=0)
    {
        p2=p2->Next;
    }
    return p2;

};

void savePlayersInFile(struct TEAM* T1,struct TEAM* T2)
{

    FILE* fptr;
    fptr=fopen("playersInfo.txt","w");// open the file in writing mode
    if(fptr==NULL)
    {
        // if the compiler failed to create a file to store the information
        printf("Sorry ... But there was a problem while creating your File \n try again later\n");
    }
    else
    {

        struct PLAYER*p1,*p2;// to points to the elementary players linked list
        p1=T1->elemantary;
        p2=T2->elemantary;
        fprintf(fptr,"The two teams were in the last match are:\n %s   and   %s\n",T1->name,T2->name);

        fprintf(fptr,"The elementary players List of %s is:\n",T1->name);

        while(p1->Next!=NULL)
        {
            fprintf(fptr,"%s\n",p1->player_name);// print the current player
            p1=p1->Next;// traverse to the next player
        }

        fprintf(fptr,"The elementary players List of %s is:\n",T2->name);
        while(p2->Next!=NULL)
        {
            fprintf(fptr,"%s\n",p2->player_name);
            p2=p2->Next;
        }
    }
    fclose(fptr);

}

void Enqueue1(char name1[20],struct TEAM* T1)
{

    struct Queue_Players* temp;
    temp=(struct Queue_Players*)malloc(sizeof(struct Queue_Players));
    // set the name of the temporary node to enqueue it
    strcpy(temp->player_name,name1);
    temp->Next=NULL;
    if(front1==NULL)
    {
        front1=rear1=temp;
       // pointer and rear points to the same node now ; because this is the first node enqueued
    }
    else
    {

        rear1->Next=temp;
        rear1=temp;
       // move only the rear when enqueue a new spare player
    }
    T1->spare=front1;//let the pointer "spare" in the team points to the first element in the queue

}

void Enqueue2(char name1[20],struct TEAM* T2)
{

    struct Queue_Players* temp;
    temp=(struct Queue_Players*)malloc(sizeof(struct Queue_Players));
    // set the name of the temporary node to enqueue it
    strcpy(temp->player_name,name1);
    temp->Next=NULL;
    if(front2==NULL)
    {
        front2=rear2=temp;
       // if this is the first node to enqueue
    }
    else
    {

        rear2->Next=temp;
        rear2=temp;
       // only the rear pointer will be moved when we enqueue a new player
    }
    T2->spare=front1;

}

void elementaryToSpare(struct TEAM* T1,struct TEAM* T2)
{
/*
  this function will remove a specified player from the elementary players list put it in the last
  position in the queue, then:
  the first player in the queue will come to the elementary list
*/
    char code1[10];
    char name1[10];
    struct TEAM* t;
    printf("Enter the code of the team that you will change its players\n");
    scanf("%s",&code1);
    t=FindCode(code1);
    if(strcmp(T1->code,code1)!=0 && strcmp(T2->code,code1)!=0)
    {
        printf("Sorry! but this team is not in the match\n");
    }
    else if(strcmp(T1->code,t->code)==0)
    {
        printf("Enter the name of the elementary player to go to Spare players Queue\n");
        scanf("%s",&name1);
        DeletePlayer(name1,T1->elemantary);//Delete the player from elementary
        Enqueue1(name1,T1);//swap this player to spare Queue
        dequeue1(T1);// get the first player in spare queue and put it in elementary
    }

    else if(strcmp(T2->code,t->code)==0)
    {
        // The same previous steps but to the second team
        printf("Enter the name of the elementary player to go to Spare players Queue\n");
        scanf("%s",&name1);
        DeletePlayer(name1,T2->elemantary);//Delete the player from the elementary list
        Enqueue2(name1,T2);//swap this player from elementary to the spare
        dequeue2(T2);// get the first player in the spare queue for team 2 and put it in elementary
    }
    // message will appear to the user to let him know that the operation is done
    printf("The player was removed from elementary list and he is now in spare Queue\n");

}
void dequeue1(struct TEAM* T1){

  struct Queue_Players* temp;
  if(front1==NULL){
        // check whether the queue is empty or not
    printf("The spare Queue Players is empty! you can not import more players now!\n");
  }
  else{
    temp=front1;//this will be removed from queue insert to elementary players
    front1=front1->Next;//let the front point to the next node //change the front of the queue
    if(front1==NULL){
        //if the front now is the last element in the queue
        rear1==NULL;//front and rear now point to the same player
    }
    printf("%s\n",temp->player_name);
    Insert_player(temp->player_name,T1);// Insert the first player to the elementary players list
    free(temp);// remove the player from queue after we swap it to elementary
  }


}

void dequeue2(struct TEAM* T2){

  struct Queue_Players* temp;
  if(front2==NULL){
        // check whether the queue is empty or not
    printf("The spare Queue Players is empty! you can not import more players now!\n");
  }
  else{
    temp=front2;//this will be removed from queue insert to elementary players
    front2=front2->Next;//let the front point to the next node //change the front of the queue
    if(front2==NULL){
        //if the front now is the last element in the queue
        rear2==NULL;//front and rear now point to the same player
    }
    printf("%s\n",temp->player_name);
    Insert_player(temp->player_name,T2);// Insert the first player to the elementary players list
    free(temp);// remove the player from queue after we swap it to elementary
  }


}

