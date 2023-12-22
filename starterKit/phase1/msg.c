#include "./headers/msg.h"
static msg_t msgTable[MAXMESSAGES];
LIST_HEAD(msgFree_h);



/*initialize the msgFree list to contain all the elements of the static array of MAXMESSAGES messages.
This method will be called only once during data structure initialization.*/
void initMsgs(){
int i=0;
for(;i<MAXMESSAGES;i++){
 list_add(&msgTable[i].m_list,&msgFree_h);
}
}



void freeMsg(msg_t *m) {
    
}


/*
return NULL if the msgFree list is empty. Otherwise, remove an element from the msgFree list,
provide initial values for ALL of the messages fields and then
return a pointer to the removed element. Messages get 
reused, so it is important that no previous value persist in a
message when it gets reallocated.*/
msg_t *allocMsg() {
    if(list_empty(&msgFree_h)==1){
        return NULL;
    }
    else{
        msg_t removed_el;
        removed_el.m_list=msgFree_h;
        list_del(&msgFree_h);
        INIT_LIST_HEAD(&msgFree_h);
        return &removed_el;
    }
}

void mkEmptyMessageQ(struct list_head *head) {
}


/*
Returns TRUE if the queue whose tail is pointed to by head is empty, FALSE otherwise.*/
int emptyMessageQ(struct list_head *head) {
    if(list_empty(head)==1) return 1;
    else return 0;
}

void insertMessage(struct list_head *head, msg_t *m) {
}

/*
Insert the message pointed to by m at the head of the queue whose head pointer is pointed to by
head.*/
void pushMessage(struct list_head *head, msg_t *m) {
    list_add(m,head);
}

msg_t *popMessage(struct list_head *head, pcb_t *p_ptr) {
}

/*
Return a pointer to the first message from the queue whose head is pointed to by head. Do not
remove the message from the queue. Return NULL if the queue is empty.a*/
msg_t *headMessage(struct list_head *head) {
    if(emptyMessageQ(head)==1) return NULL;
    else{
    }
}
