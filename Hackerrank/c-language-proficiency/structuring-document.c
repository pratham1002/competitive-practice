#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

typedef struct document document;
typedef struct paragraph paragraph;
typedef struct sentence sentence;
typedef struct word word;

struct document get_document(char *text) {
    /*  document is doc
    *   paragraph is doc->data
    *   sentence is doc->data->data
    *   word is doc->data->data->data
    */
    document *doc = (document *)malloc(sizeof(document));
    doc->data = (paragraph *)malloc(sizeof(paragraph));
    doc->data->data = (sentence *)malloc(sizeof(sentence));
    doc->data->data->data = (word *)malloc(sizeof(word));

    doc->paragraph_count = 1;
    doc->data->sentence_count = 1;
    doc->data->data->word_count = 1;

    char w[1000];
    memset(w, 0, sizeof(w));
    int p = 0;

    while(*text != '\0') {
        // continue the same word 
        if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z')) {
            // printf("inserting new character: %c\n", *text);
            w[p++] = *text;
            text++;
            // printf("word is: '%s'\n", w);
        }

        // new word 
        if (*text == ' ') {
            // printf("adding new word: '%s'\n", w);
            // printf("para count = %d\n", doc->paragraph_count);
            paragraph *para = doc->data + doc->paragraph_count - 1;
            // printf("sentence count = %d\n", para->sentence_count);
            sentence *sent = para->data + para->sentence_count - 1;
            // printf("word count = %d\n", sent->word_count);
            word *wor = sent->data + sent->word_count - 1;
            // printf("word count = %d, paragraph count = %d, sentence count = %d\n", sent->word_count, doc->paragraph_count, para->sentence_count);

            wor->data = (char *)malloc(strlen(w) + 1);
            // printf("malloc success allocated %lu \n", strlen(w) + 1);
            strcpy(wor->data, w);
            memset(w, 0, sizeof(w));
            p = 0;
            // printf("word copying success: %s\n", wor->data);
            // printf("the sentence starts with:\t%s\n", sent->data->data);

            // printf("word count before realloc and increment = %d, paragraph count = %d, sentence count = %d\n", sent->word_count, doc->paragraph_count, para->sentence_count);
            sent->word_count += 1;
            sent->data = (word *)realloc(sent->data, sizeof(word) * (sent->word_count));
            // printf("word count after realloc and increment = %d\n", sent->word_count);

            word *new_wor = sent->data + sent->word_count - 1;
            new_wor = (word *)malloc((sizeof(word)));
            new_wor->data = NULL;
            text++;
            // printf("inserted new word and initialised new word\n");
            // printf("word count at end of if block = %d\n", sent->word_count);
        }

        if (*text == '.') {
            // printf("adding new word: '%s' at end of sentence\n", w);
            paragraph *para = doc->data + doc->paragraph_count - 1;
            sentence *sent = para->data + para->sentence_count - 1;
            word *wor = sent->data + sent->word_count - 1;

            wor->data = (char *)malloc(sizeof(w));
            wor->data = (char *)malloc(strlen(w) + 1);
            // printf("malloc success allocated %lu \n", strlen(w) + 1);
            strcpy(wor->data, w);
            memset(w, 0, sizeof(w));
            p = 0;
            // printf("word copying success: %s\n", wor->data);

            // sent->word_count += 1;
            // printf("sentence count before realloc = %d\n", para->sentence_count);
            para->sentence_count += 1;

            para->data = (sentence *)realloc(para->data, para->sentence_count * sizeof(sentence));
            // printf("sentence count after realloc = %d, word count before realloc = %d\n", para->sentence_count, sent->word_count);

            // sent->data = (word *)realloc(sent->data, sizeof(word) * (sent->word_count));

            sentence *new_sent = para->data + para->sentence_count - 1;
            new_sent->data = (word *)malloc(sizeof(word));
            new_sent->word_count = 1;
            // printf("word cound of new sentence is = %d\n", (para->data + para->sentence_count - 1)->word_count);
            word *new_wor = new_sent->data;
            // new_wor = (word *)malloc((sizeof(word)));
            new_wor->data = NULL;
            text++;
            // printf("inserted new sentence and initialised new word\n");
        }

        if (*text == '\n') {
            (doc->data + doc->paragraph_count - 1)->sentence_count -= 1;
            // printf("Inserting new paragraph\n");
            doc->paragraph_count += 1;
            // printf("number of paragraphs for realloc = %d\n", doc->paragraph_count);
            doc->data = (paragraph *)realloc(doc->data, doc->paragraph_count * sizeof(paragraph));

            paragraph *new_para = doc->data + doc->paragraph_count - 1;
            // new_para = (paragraph *)malloc(sizeof(paragraph));
            new_para->sentence_count = 1;
            new_para->data = (sentence *)malloc(sizeof(sentence));
            // printf("sentence count for new para = %d\n", new_para->sentence_count);
            sentence *new_sent = new_para->data;
            // new_sent = (sentence *)malloc(sizeof(sentence));
            new_sent->word_count = 1;
            new_sent->data = (word *)malloc(sizeof(word));
            word *new_wor = new_sent->data;
            // new_wor = (word *)malloc((sizeof(word)));
            new_wor->data = NULL;
            text++;
        }
        if (*text == '\0') {
            (doc->data + doc->paragraph_count - 1)->sentence_count -= 1;
        }
    }
    // printf("Final paragraph count = %d\n", doc->paragraph_count);
    doc->paragraph_count -= 1;
    return *doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    // printf("called word find\n");
    struct paragraph *para = Doc.data + n - 1;
    struct sentence *sent = para->data + m - 1;
    struct word *w = sent->data + k - 1;

    return *w;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    // printf("called sentence find\n");
    struct paragraph *para = Doc.data + m - 1;
    struct sentence *sent = para->data + k - 1;

    return *sent;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    // printf("called word find\n");
    struct paragraph *para = Doc.data + k - 1;
    return *para;
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}