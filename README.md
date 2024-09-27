# 기술 명세서: 포커를 이용한 전투 텍스트 RPG

## 1. 개요

본 프로젝트는 포커 게임 메커니즘을 활용한 텍스트 기반 RPG입니다. 플레이어는 던전에서 적과 전투를 통해 골드를 얻고, 상점에서 아이템을 구매하여 강해지며 더 높은 스테이지에 도전합니다.

## Flow chart


![FlowChart](https://github.com/user-attachments/assets/8b1ca128-370d-4d49-8133-213faf784618)

---

## 2. 시스템 구성

### 2.1 씬 관리 (SceneManager)

- **기능**: 다양한 게임 씬을 관리하고 전환합니다.
- **씬 종류**:
    - 시작 화면
    - 로비
    - 상점
    - 인벤토리
    - 던전
    - 전투


### 2.2 유닛 클래스 (Player/Enemy)

- **기능**: 플레이어와 적을 생성 및 관리합니다.
- **변수**:
    - 이름 (String)
    - 체력 (int)
    - 골드 (int)
    - 공격력 (int)
- **메서드**:
    - `attack()`: 적에게 공격
    - `TakeDamage()`: 피해 수치 처리
      

### 2.3 아이템 클래스 (Item)

- **기능**: 게임 내 아이템을 생성 및 관리합니다.
- **변수**:
    - 이름 (String)
    - 공격력 (int)
    - 가격 (int)
- **메서드**:
    - `equippedItem()`: 아이템 사용 시 효과 적용
    

### 2.4 스테이지 관리 (StageManager)

- **기능**: 스테이지 정보를 관리하여 게임의 구조를 간결하게 유지합니다.
- **변수**:
    - 현재 스테이지 번호 (int)
    - 적 정보 (Enemy)
- **메서드**:
    - `nextStage()`: 다음 스테이지로 이동
    

## 3. 게임 진행

### 3.1 시작 화면

- **기능**: 게임 시작 및 종료 옵션 제공
- **입력**: ↑, ↓ (옵션 선택), Enter (선택)

### 3.2 로비

- **기능**: 게임의 메인 허브 역할
- **버튼**:
    - 상점
    - 인벤토리
    - 던전
    - 시작 화면으로 나가기
- **입력**: ↑, ↓ (옵션 선택), Enter (선택)

### 3.3 상점

- **기능**: 아이템 구매
- **조건**: 플레이어의 돈 소모
- **입력**: ↑, ↓ (아이템 선택), Enter (구매)

### 3.4 인벤토리

- **기능**: 보유 아이템 정보 출력 및 관리
- **조건**: 아이템 장착 및 교체 가능
- **입력**: ↑, ↓ (아이템 선택), Enter (장착/교체)

### 3.5 던전

- **기능**: 전투를 위한 스테이지 진입
- **옵션**: 전투, 로비로 돌아가기

## 4. 전투

### 4.1 전투 메커니즘

- **기능**: 포커를 통해 전투 진행
- **규칙**:
    - 플레이어와 적이 각각 4장씩 드로우 후 1장 버림
    - 이후 2장 추가 드로우
    - 포커 족보 비교 후 피해 결정
- **데미지 계산**:
    - 족보에 따라 다양한 데미지 계산
    - ex) 탑 = 공격력 * 0.8, 원페어 = 공격력 * 1.0

### 4.2 전투 결과

- **승리 시**: 몬스터의 골드만큼 골드 획득, 다음 스테이지 진입
- **패배 시**: 몬스터의 골드만큼 골드를 잃고 로비로 돌아감

## 5. 포커 클래스

- **기능**: 포커 게임 메커니즘 구현
- **변수**:
    - 플레이어 핸드 (ArrayList<Card>)
    - 적 핸드 (ArrayList<Card>)
- **메서드**:
    - `draw()`: 카드 드로우
    - `chooseTrashCards()`: 카드 버림
    - `evaluateHand()`: 핸드 평가 및 족보 결정
    - `BubbleSort()`: 카드 정렬 후 스트레이트 판별
    
    ---
    

## 6. 개발 환경

- **언어**: C++
- **프레임워크**: console
- **개발 도구**: Visual Studio

---

## 7. 추가 기능 및 고려 사항

- **세이브/로드**: 게임 진행 상황 저장 및 불러오기 기능
- **다양한 스테이지**: 각 스테이지마다 적과 보상 다양화
- **UI 개선**: 텍스트 출력 시 사용자 경험을 고려한 UI 설계

## 8.깃허브

https://github.com/wkdtjsdndlqslek/ConsoleProject.git

https://github.com/wkdtjsdndlqslek/ConsoleProject.git
