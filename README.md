***혹시 원격 분기로 브랜치가 나뉘어 커밋이 안된다면 '커밋-점세개(보기 및 기타 작업)-분기-병합-병합할 브랜치 선택'으로 해결 가능***

23-07-24
    1차시
        VMware 설치
        UBUNTU 22.04 설치
        github 계정 만들기
        terminator 설치
        git 설치
    2차시
        VScode 설치
        github 연동
    3차시
        opencv의 이미지 출력 코드 및 point, size, rect 등 연산자 활용

24-07-24
    1차시
        Matrix class 활용: Scalar를 통한 이미지 색상 지정 및 변경, 이미지 복사
    2차시
        행렬에 for문, point, iterator를 적용한 변화 확인
    3차시
        VideoCapture를 이용한 카메라 동작(실패)->video 재생 및 frame 조절
        line, putText를 활용하여 line, text를 이미지에 포함시키기
    과제
        md 작성법
        make 기본 사용법
        cmake 기본 사용법
        cmake 총정리

25-07-24
    1차시
        setMouseCallback을 이용한 마우스 이벤트 코드: 마우스 클릭으로 lenna 이미지에 선 그리기
        트랙바 사용: 이미지에 직선 긋기, 명암 조절 등 기능을 탑재한 스크롤 추가
    2차시
        FileStorage 클래스: 특정 자료를 index로 정리하여 .json 파일 형식으로 저장/저장한 파일에서 특정 정보만 읽어 화면에 출력 
        Mask 연산: setTo, copyTo, GRAYSCALE리딩으로 이미지 합성하기
        실습예제: 이미지 위 마우스 위치에 사각형 생성, 클릭 위치의 BGR값 출력 및 저장
    3차시
        예제 정답 풀이
        cvtColor, IMREAD_명령문으로 이미지 색변화 및 밝기 조절
        histogram: 이미지의 밝기 분포 도식화 및 명암비 조절을 통한 선명도 변화 관찰
        영상의 연산자
        블러링과 샤프닝: GaussianBlur 필터와 alpha, sigma 값 조절, bilateralFilter로 영상의 선명도 조절

26-07-24
    1차시
        어파인 변환, 투시 변환으로 영상 회전 및 변환
        캐니, 허프 변환으로 영상 속 픽셀이 급변하는 지점-edge-와 line을 검출한 자료 생성
    2차시
        split, merge를 활용한 영상의 색상 채널 분화
        inRange로 특정 색상 영역을 마스킹
    3차시
        threshold: 영상 속 픽셀을 0과 1로 이진화
        모폴로지: 영상 속 객체에 침식, 팽창을 적용하여 노이즈를 제거
    4차시
        레이블링과 외곽선 검출(이론)
        템플릿 매칭: 찾고자하는 대상이 되는 작은 크기의 영상-템플릿-과 입력 영상을 비교하여 비슷한 객체를 검출
        코너 검출: 영상 안에서 객체가 뾰족하게 튀어나온 부분-코너, 특징점-을 변별하여 두 영상의 객체가 동일한지 매칭

30-07-24
    1차시   
        ROS2 이론 교육: 노드, 토픽, 메시지, 런처, 노드 통신 및 실행
    2차시
        ROS2 humble 설치: ros2 humble documentation debian installation
        환경 설정 파일 (.bashrc) 수정:
            source /opt/ros/humble/setup.bash -> 터미널 실행 시 ROS 실행
            source ~/xxx_ws/install/local_setup.bash
            여러가지 alias(명령어 단축키) 설정
            export ROS_DOMAIN_ID 설정
    3차시
        워크 스페이스 및 패키지 작성: simple_pkg_cpp
        xml, CMakeLists.txt 수정
        노드 추가
            helloworld.cpp : 기본 main 코드
            helloOpenCV.cpp : OpenCV 사용 코드(외부 라이브러리 적용을 위한 CMakeLists 수정)
            hello_publisher : Node 및 spin timer 적용
            hello_publisher_class : Node 상속 클래스 적용

31-07-24


