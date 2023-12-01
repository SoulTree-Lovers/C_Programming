#include <stdio.h> 
#include <string.h> 
#define SIZE 100 

typedef struct person {
    char name[SIZE];
    char address[SIZE]; // 주소 
    char mobilephone[SIZE]; 
    char desc[SIZE];
} PERSON;

void menu();
PERSON get_record();
void print_record(PERSON data); 
void add_record(FILE *fp);
void search_record(FILE *fp); 
void update_record(FILE *fp);


int main() {
    FILE *fp;
    int select;

    if ((fp = fopen("address.dat", "a+")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        return 1;
    }

    while (1) {
        menu();
        printf("정수값을 입력하세요: ");
        scanf("%d", &select);

        switch (select) {
        case 1:
            add_record(fp); break;
        case 2:
            update_record(fp); break;
        case 3:
            search_record(fp); break;
        case 4:
            return 0;
        }
    }
    fclose(fp);
    return 0;
}

PERSON get_record() {
    PERSON data;
    fflush(stdin);
    printf("이름: "); gets(data.name);
    printf("주소: "); gets(data.address);
    printf("휴대폰: "); gets(data.mobilephone);
    printf("특징: "); gets(data.desc);
    return data;
}

void print_record(PERSON data) {
    printf("이름: %s\n", data.name);
    printf("주소: %s\n", data.address);
    printf("휴대폰: %s\n", data.mobilephone);
    printf("특징: %s\n", data.desc);
}

void menu() {
    printf("====== 메뉴 ======\n");
    printf("1. 추가\n");
    printf("2. 수정\n");
    printf("3. 검색\n");
    printf("4. 종료\n");
    printf("==================\n");
    printf("\n");
}

void add_record(FILE *fp) {
    PERSON data = get_record();
    fseek(fp, 0, SEEK_END);
    fwrite(&data, sizeof(PERSON), 1, fp);
}


void search_record(FILE *fp) {
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET);
    fflush(stdin);

    printf("탐색할 사람 이름: ");
    gets(name);

    int found = 0; // 이름을 찾았는지 여부를 나타내는 변수

    while (!feof(fp)) {
        fread(&data, sizeof(data), 1, fp);
        if (strcmp(data.name, name) == 0) {
            print_record(data);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("해당하는 이름이 없습니다.\n");
    }
}

// 레코드를 업데이트하는 함수
void update_record(FILE *fp) {
    PERSON data;
    char name[SIZE];

    // 파일 포인터를 파일의 맨 처음으로 이동
    fseek(fp, 0, SEEK_SET);
    fflush(stdin);

    // 사용자로부터 수정할 사람의 이름을 입력 받음
    printf("수정할 사람 이름: ");
    gets(name);

    int found = 0; // 이름을 찾았는지 여부를 나타내는 변수

    // 파일의 끝에 도달할 때까지 루프 실행
    while (!feof(fp)) {
        // 파일에서 레코드를 읽어옴
        fread(&data, sizeof(data), 1, fp);

        // 입력된 이름과 현재 레코드의 이름이 일치하는지 확인
        if (strcmp(data.name, name) == 0) {
            // 수정할 레코드를 사용자로부터 입력 받음
            PERSON updatedData = get_record();

            // 현재 파일 포인터를 수정할 레코드의 시작 위치로 이동
            fseek(fp, -sizeof(data), SEEK_CUR);

            // 수정된 레코드를 파일에 씀
            fwrite(&updatedData, sizeof(PERSON), 1, fp);

            found = 1; // 이름을 찾았음을 표시
            break;
        }
    }

    // 이름을 찾지 못했을 경우 메시지 출력
    if (!found) {
        printf("해당하는 이름이 없습니다.\n");
    }
}
