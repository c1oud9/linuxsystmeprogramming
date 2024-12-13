
#define MY_ID  1
// MY_ID는 프로세스의 역할 정의
// 0은 생산자(producer), 1은 소비자(consumer)
// 현재 설정은 1이므로 이 프로세스는 소비자 역할 수행

#define SHM_KEY (0x9000 + MY_ID)
// SHM_KEY는 공유 메모리의 키 값 정의
// 0x9000에 MY_ID를 더해 고유한 키 값을 생성
// 이를 통해 생산자와 소비자가 같은 공유 메모리를 사용 가능

#define SHM_MODE (SHM_R | SHM_W | IPC_CREAT)
// SHM_MODE는 공유 메모리의 접근 권한을 설정
// SHM_R: 읽기 권한 (Read permission)
// SHM_W: 쓰기 권한 (Write permission)
// IPC_CREAT: 공유 메모리가 존재하지 않으면 새로 생성
// 이 세 가지 플래그를 비트 OR 연산으로 결합하여 사용

// 세마포어 키 정의
#define EMPTY_SEM_KEY (0x5000 + MY_ID)
// 빈 버퍼의 수를 관리하는 세마포어의 키

#define FULL_SEM_KEY (0x6000 + MY_ID)
// 채워진 버퍼의 수를 관리하는 세마포어의 키

#define MUTEX_SEM_KEY (0x7000 + MY_ID)
// 상호 배제(mutual exclusion)를 위한 세마포어의 키

#define NLOOPS 20
// 생산 또는 소비 작업을 반복할 횟수

#define MAX_BUF 2
// 버퍼의 최대 크기

typedef struct {
    int data;
} ItemType;
// 버퍼에 저장될 데이터 아이템의 구조체 정의

typedef struct {
    ItemType buf[MAX_BUF];  // 실제 데이터를 저장하는 버퍼 배열
    int in;                 // 데이터를 넣을 위치 인덱스
    int out;                // 데이터를 꺼낼 위치 인덱스
    int counter;            // 현재 버퍼에 저장된 아이템의 개수
} BoundedBufferType;
// 유한 버퍼의 구조체 정의

#define SHM_SIZE sizeof(BoundedBufferType)
// 공유 메모리의 크기를 BoundedBufferType 구조체의 크기로 정의
