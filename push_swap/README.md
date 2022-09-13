# PUSH SWAP

## 1.과제의 목적

> - 복잡도 개념에 대해 공부 한다
> - 정렬 알고리즘에 대해 공부 한다  
> -> 가장 빠른 방법으로 정렬을 실행할 수 있을까?  
> -> 초기 수열에 따라 가장 빠른 알고리즘이 다를 수도?  
> ex) 퀵소트 평균 : O(nlogn) 최악 : O(n^2)

## 2. 과제전 알아야할 내용  
1. exit() 함수  
	1. 기능  
	- terminate processs  
		i. call the functions resgistered with the atexit(3) function, in the reverse order of their registration.  
		ii. flush all open outpu streams  
		iii. close all open streams  
		iv. unlink all files created with the tmpfile(3) function  
  
	2. 시간 복잡도  
	- 특정한 크기의 입력에 대하여 알고리즘이 얼마나 오래 걸리는지를 의미함  
	- 알고리즘을 위해 필요한 연산의 횟수  

	3. 공간 복잡도  
	- 특정한 크기의 입력에 대하여 알고리즘이 얼마나 많은 메모리를 차지하는지 의미함  
	- 알고리즘을 위해 필요한 메모리의 양  

## 3. 구현 전 연습 목록  

- [x] 이중연결리스트 구현
- [x] 이중연결리스트에 값 저장하기
- [x] 선택정렬로 이중연결리스트 정렬해보기
- [x] 병합정렬로 이중연결리스트 정렬해보기
- [x] 퀵정렬로 이중연결리스트 정렬해보기
- [x] 과제에 주어진 함수 구현하고 해당 함수 사용시 리스트 변경 될 수 있도록 해보기
- [ ] 최적화된 정렬 알고리즘 구현 해보기
- [ ] 올바른 입력값만 받을 수 있도록 파싱 하기

