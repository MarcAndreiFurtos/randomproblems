/*Let there be a Zoom online conference session management system, each with a Waiting Room
that houses students. A conference is characterized by a unique meeting ID (Meeting ID)
and an access password, and students by a display name. Write and implement an appropriate
multilist structure for managing these conferences. The structure will have the following
components: Each conference is a separate entry in a main list, and each conference contains a
secondary list sorted alphabetically by student name (at least one of the lists will be
implemented dynamically)
Implement the necessary data structures and the following functionalities:
Acceptance in meetings of all students whose names begin with a letter read from the keyboard.
Acceptance implies the deletion of students who respect the condition of Waiting
Rooms
Choose an example list that includes at least 3 conferences, each with at least 5 students. Graph
the multi-list structure for this example, before and after calling the Acceptance in meetings
function.
Note:
Algorithm may be written in C-like pseudocode.
It is mandatory to comment on the algorithm and specify its complexity in terms of O (f (n),
comment on the chosen data structures, as well as justify their choice.
It is mandatory to exemplify the call effect of the functions implemented on a chosen example.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// creating linked list node for students
typedef struct Student{
    char name[50];
    struct Student *next;
}student;

// creating conference with 2 pointers to start of linked lists for waiting and conference
typedef struct Conference{
    char meetingID[50];
    char password[50];
    student *waitingRoom;
    student *inConference;
}conference;

// global variables for the list of conferences
conference * mainList[100];
int conferencesInList = 0;

// function to be used in other functions to create a new student ,acts as a constructor
student *createNewStudent(char name[50]){
    student *newStudent = NULL;
    newStudent = (student*)malloc(sizeof(student));
    //verifying if alocation succesfull
    if(!newStudent){
        free(newStudent);
        return NULL;
    }
    strcpy(newStudent->name,name);
    newStudent->next = NULL;
    return newStudent;
}

// function to be used in other functions to create a new conference ,acts as a constructor
conference *createNewConference(char meetingID[50], char password[50]){
    conference *newConference = NULL;
    newConference =(conference*)malloc(sizeof(conference));
    //verifying if alocation succesfull
    if(!newConference){
        free(newConference);
        return NULL;
    }
     strcpy(newConference->meetingID,meetingID);
     strcpy(newConference->password,password);
     newConference->waitingRoom = NULL;
     newConference->inConference = NULL;

     return newConference;
}

// function to add a new conference to the main list
conference *addConferenceToMainList(char meetingID[50], char password[50]){
    // if the limit is reached it prints an error and exits the function
    // else it creates a new conference and adds it to the list incrementing the number
    // of conferences
    if(conferencesInList == 100 ){
        printf("conference limit reached");
        return;
    }
    conference *newConf = createNewConference(meetingID,password);
    mainList[conferencesInList] = newConf;
    conferencesInList++;
    return newConf;
}

// function to create a node and add it before the head in the linked list
void addStudentBeforeHead(student **head, char name[50]){
    student *newSt = createNewStudent(name);
    newSt->next = *head;
    *head = newSt;
}

// function to create a node and add it after a diferent node in the linked list 
void addStudentAfterNode(student *s ,char name[50]){
    student *newS = createNewStudent(name);
    newS->next = s->next;
    s->next = newS; 
}

// this function adds a studentto the waiting room in an unordered fasion 
// c->waiting room acts as the head of the list 
void addToWaitingRoom(conference *c , char name[50]){
    if(c->waitingRoom = NULL){
        c->waitingRoom = createNewStudent(name);
    }
    else{
    addStudentBeforeHead(&c->waitingRoom,name);
    }
}

// same as the last one but it adds it in an ordered fasion based on the name of the student
// and the name of the students allready in the list
void addToSession(conference *c , char name[50]){
    // if head doesn't exist create it
    if (c->inConference = NULL){
        c->inConference = createNewStudent(name);
    } 
    // if ascii value of name is smaller or equal than that of head it adds it first 
    else if(strcmp(name,c->inConference->name)<=0){

        addStudentBeforeHead(&c->inConference ,name);
    }
    // if not it searches for the correct place to insert
    else{
        // itterating through all the nodes to find the place where to insert the node in order
        student *s =NULL;
        for(s = c->inConference ; s->next!=NULL ; s = s->next){
            if (strcmp(name ,s->name)>0){
                addStudentAfterNode(s,name);
            }
        }
    }
}

// function that decides weather to add a student to the session or the waiting room based on 
// the first letter of his name and the keyboard input 
void addStudent(conference *c , char name[50],char a){
    if(name[0] == a){
        addToSession(c,name);
    }
    else{
        addToWaitingRoom(c,name);
    }
}

int main(){
    // initalizing conference list
    for(int i = 0 ; i < 100 ; i++){
        mainList[i] = (conference*)malloc(sizeof(conference));
    }

    // driver code and examples
    char a;
    scanf("%c" , &a);
    conference *conf1 = addConferenceToMainList("123", "abc");
    conference *conf2 = addConferenceToMainList("382479" , "klasdfhj");
    conference *conf3 = addConferenceToMainList("5489032" , "kdglf");
    // adding students
    addStudent(conf1,"ana",a);
    addStudent(conf1,"dani" ,a);
}