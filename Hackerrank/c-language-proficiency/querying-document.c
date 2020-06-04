#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    // return *(*(*(document + n - 1) + m - 1) + k - 1);
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    // return *(*(document+m - 1) + k - 1);
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    // return *(document+k-1);
    return document[k-1];
}

char**** get_document(char* text) {
    // printf("get_document called \n");

    char ****document;
    document = (char ****)malloc(sizeof(char ***));     // entire document
    *document = (char ***)malloc(sizeof(char **));      // for paragraphs
    **document = (char **)malloc(sizeof(char *));       // for sentences
    // ***document = (char *)malloc(sizeof(char));         // for word
    ***document = NULL;

    int num_paragraphs = 1;
    int num_sentences = 1;
    int num_words = 1;
    int current_word_length = 0;

    // enter the first character in the document
    // ****document = *(text);
    // text += 1;
    char word[100000];
    int p = 0;
    while(*(text) != '\0') {
        // char c = *text;
        // text++;
        // continue the same word 
        if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z')) {
            // printf("%c ", *text);
            // printf("in = %s\n", document[num_paragraphs-1][num_sentences-1][num_words-1]);
            // current_word_length += 1;
            // document[num_paragraphs-1][num_sentences-1][num_words-1] = (char *)realloc(document[num_paragraphs-1][num_sentences-1][num_words-1], current_word_length);
            // document[num_paragraphs-1][num_sentences-1][num_words-1][current_word_length-1] = *text;
            // printf("current word lentgth = %d, out = %s\n", current_word_length,document[num_paragraphs-1][num_sentences-1][num_words-1]);
            // text++;
            word[p++] = *text;
            text++;
        }

        // new word 
        if (*text == ' ') {
            // current_word_length = 0;
            document[num_paragraphs-1][num_sentences-1][num_words-1] = (char *) malloc(sizeof(word));
            strcpy(document[num_paragraphs-1][num_sentences-1][num_words-1], word);
            memset(word,0,sizeof(word));
            p = 0;
            num_words += 1;

            document[num_paragraphs-1][num_sentences-1] = (char **)realloc(document[num_paragraphs-1][num_sentences-1], sizeof(char *) * num_words);
            document[num_paragraphs-1][num_sentences-1][num_words-1] = NULL; 
            text++;
        }

        // new sentence
        if (*text == '.') {
            document[num_paragraphs-1][num_sentences-1][num_words-1] = (char *) malloc(sizeof(word));
            strcpy(document[num_paragraphs-1][num_sentences-1][num_words-1], word);
            memset(word,0,sizeof(word));
            p = 0;
            current_word_length = 0;
            num_words = 1;
            num_sentences += 1;

            document[num_paragraphs-1] = (char ***)realloc(document[num_paragraphs-1], sizeof(char **) * num_sentences);

            document[num_paragraphs-1][num_sentences-1] = (char **)malloc(sizeof(char *));

            document[num_paragraphs-1][num_sentences-1][0] = NULL;

            text++;
        }

        if (*text == '\n') {
            current_word_length = 0;
            num_words = 1;
            num_sentences = 1;
            num_paragraphs += 1;

            document = (char ****)realloc(document, sizeof(char ***) * num_paragraphs);

            *(document + num_paragraphs - 1) = (char ***)malloc(sizeof(char **));

            **(document + num_paragraphs - 1) = (char **)malloc(sizeof(char *));

            ***(document + num_paragraphs - 1) = NULL; 

            text++; 
        }
    }
    // printf("\n");
    return document;
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

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}