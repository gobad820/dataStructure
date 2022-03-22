<!-- https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblE5UmpRc2VMR0V2ZXF2NDd6V2VXOFdZUzNpQXxBQ3Jtc0trZUVLOEZmSjJnUVR5WHBkLTlTQ01OOWlJVVF2Zm9GUnFsdG52RjZUZXhiSzVSTGJLbUNXT2luV2R3TFVMUmkyX0w4emg5cmxxNFlwVnN6dTE5NkRsVW9aUmgtQUVVR2FLalJPdDJBNnhKZ0hsblhhRQ&q=http%3A%2F%2Fincompetech.com%2Fmusic%2Froyalty- -->

# Object

## 1.1 객체 생성하기

---

### 9.1.1 객체의 생성

---

- 객체 : 이름과 값을 한 쌍으로 묶은 집합
- 프로퍼티 : 이름과 값이 한 쌍을 이룬 것
  - 이름 : 프로퍼티 이름, 또는 키
  - 값으로는 데이터

1. 객체 리터럴로 생성

   ```js
   var card = { suit: "HEART", rank: "A" };
   ```

1. 생성자로 생성

   ```JS
   function Card(suit,rank){
     this.suit = suit;
     this.rank = rank;
   }
   ```

1. Object.create로 생성

   ```javascript
   var card = Object.create(Object.prototype, {
     suit: {
       value: "Heart",
       writable: true,
       enumarable: true,
       configurable: true,
     },
     rank: {
       value: "A",
       writable: true,
       enumarable: true,
       configurable: true,
     },
   });
   ```

---

### 9.1.2 Prototype

---

#### 생성자 안에서 메서드 정의하는 방식의 문제점

- 생성자 안에서 this뒤의 메서드 정의 그 생성자로 생성한 모든 인스턴스에 똑같은 메서드가 추가된다.
- 안쓰는 메서드, 메모리를 소비가 많아진다.

  ```js
  function Circle(center, radius) {
    this.center = center;
    this.radius = radius;
    this.area = function () {
      return;
      Math.PI * this.radius * this.radius;
    };
  }
  var c1 = new Circle({ x: 0, y: 0 }, 2.0);
  var c2 = new Circle({ x: 0, y: 1 }, 3.0);
  var c3 = new Circle({ x: 1, y: 1 }, 1.0);
  ```

#### 프로토타입의 객체

- 함수도 객체이므로 함수 객체가 기본적으로 _prototype_ 프로퍼티를 갖고 있다.

  ```JS
  function F() {};
  console.log(F.prototype);
  ```

- 함수 prototpye 프로퍼티가 가리키는 객체 = 프로토타입의 객체

- prototype 프로퍼티는 기본적으로 빈 객체를 가리킴

- 프로토타입 객체의 프로퍼티는 생성자로 생성한 모든 인스턴스에서 그 인스턴스의 프로퍼티처럼 사용할 수 있다.

  ```js
  F.prototype.prop = "prototype value";
  var obj = new F();
  console.log(obj.prop);
  ```

- 프로토타입 객체의 프로퍼티는 읽기만 가능하고 수정이 불가능하다.

  ```js
  obj.prop = "instance value";
  console.log(obj.prop); // instance value
  console.log(F.prototype.prop); // prototype value
  ```

- 인스턴스에서 참조할 수 있는 상황을 가리켜 인스턴스가 프로토타입 객체를 상속하고 있다라고 한다.

- this 뒤에 메서드를 정의할 때 생기는 문제는 생성자의 프로터타입 객체에 메서드를 추가하는 방식으로 해결할 수 있다.

  ```JS
  function Circle(center, radius){
    this.center = center;
    this.radius = radius;
  }
  Circle.prototype.area = function(){
    return Math.PI*this.radius*this.radius;
  }
  var c1 = new Circle({x:0, y:0},2.0);
  var c2 = new Circle({x:1, y:0},3.0);
  var c3 = new Circle({x:0, y:1},1.0);
  ```

---

## 9.2 프로토타입의 상속

---

### 9.2.1 상속

---

- 상속: 특정 객체가 다른 객체로부터 기능을 이어받는 것

### 9.2.2 상속 하는 이유

---

- 유지 보수성이 높다

### 9.2.3 프로토타입 체인

---

- 내부 프로퍼티 [[prototype]]

  - 모든 객체는 내부 프로퍼티 [[prototype]] 을 가지고 있다.

  - 함수 객체의 prototype 프로퍼티와 다른 객체

    ```JS
    var obj = {};
    console.log(obj.__proto__); // Object {}
    ```

- 프로토타입 체인

  - `__`proto`__`프로터니는 그 객체에게 상속을 해 준 부모 객체를 가리킨다.

    ```JS
      var objA = {
        name: "Tom",
        sayHello: function(){
          console.log("Hello! "+this.name);
        }
      }
      var objB = {
        name: "Huck",
      }
      objB.__proto__ = objA;
      var objC = {};
      objC.__proto__ = objB;
      objC.sayHello();
    ```

  - 프로토타입 체인 : `__proto__` 프로퍼티가 가리키는 객체를 차례대로 거슬러 올라가며 검색하는데, 이와 같은 객체의 연결고리를 프로토타입 체인이라고 한다.

  - 객체는 자신이 가지고 있지 않은 특성을 프로토타입 객체에 위임한다.

  - 프로토타입 가져오기

    - Object.getPrototypeOf 메서드를 통해 가져올 수 있다.

    ```JS
    function F() {}
    var obj = new F();
    console.log(Object.getPrototypeOf(obj)); // Object {}
    ```

### 9.2.4 new 연산자

---

```JS
function Circle(center, radius){
  this.center = center;
  this.radius = radius;
};
Circle.prototype.area = function(){
  return Math.PI*this.radius*this.radius;
};
```

- 위의 new연산자로 Circle 생성자를 사용하면 내부적으로는

  ```js
  var newObj = {};
  newObj.__proto__ = CIrcle.prototype;
  Circle.apply(newObj, arguments);
  return newObj;
  ```

- prototype 프로퍼티 값을 인스턴스의 \_\_proto\_\_ 프로퍼티 값으로 대입 하면서 인스턴스의 `프로토타입 체인` 이 정의된다.

- 생성자로 생성한 모든 인스턴스가 생성자의 프로토타입 객체의 프로퍼티 사용 가

### 9.2.5 프로토타입 객체의 프로퍼티

---

- Constructor 프로퍼티

  ```JS
  function F() {};
  console.log(F.prototype.constructor); // function F() {}
  ```

  - constructor 프로퍼티 함수는 개체의 참조를 값으로 갖고 있다.
  - 객체의 생성자의 prototype 프로퍼티가 프로토타입을 가리키고 프로토타입의 constructor 프로퍼티가 생성자를 가리킨다.
  - 생성된 인스턴스는 프로토타입 객체의 참조만 가지고 있을 뿐 생성자와 직접적인 연결 고리는 없다.

- 내부 프로퍼티 [[prototype]]

  - 함수 객체는 기본적으로 Object.prototype을 가리킨다.
  - 프로토타입 객체의 프로토타입 = Object.prototype
  - 이 덕분에 인스턴스틑 Object.prototype의 프로퍼티를 이용 가능하다.
  - Object.prototype의 프로토타입 = null

    ```js
    function F() {}
    var obj = new F();
    console.log(obj.__proto__); // F {}
    console.log(obj.__proto__.__proto__); // {}
    console.log(obj.__proto__.__proto__.__proto__); // null
    ```

- 프로토타입 객체의 교체 및 constructor 프로퍼티

  - 프로퍼티만 정의되어 있는 새로운 객체를 prototype 프로퍼티 값으로 대입하면 인스턴스와 생성자 사이이 연결 고리가 끊김.
    - 그 객체에는 constructor 프로퍼티가 없기 때문
  - 고리르 유지하려면 prototype으로 사용할 객체에 constructor 프로퍼티 정의, 생성자의 참조 대입해야 한다.

    ```js
    function Circle(center, radius) {
      this.center = center;
      this.radius = radius;
    }
    Circle.prototype = {
      constructor: CIrcle, // 생성자를 constructor로 대입
      area: function () {
        return Math.PI * this.radius * this.radius;
      },
    };
    var c = new Circle({ x: 0, y: 0 }, 2.0);
    console.log(c.constructor);
    console.log(c instanceof Circle); // true
    ```

- 인스턴스 생성 후 생성자 프로토타입 수정하거나 교체한 경우

  - 인스턴스 프로토타입 : 인스턴스를 생성할 때 가지고 있던 프로토타입 객체 -인스턴스 생성 후 생성자의 prototype 프로퍼티 값을 다른 객체로 교체해도 인스턴스 프로토타입은 바뀌지 않는다. -인스턴스는 생성된 시점의 프로토타입에서 상속 받는다

    ```JS
    function Circle(center, radius){
    this.center = center;
    this.radius = radius;
    }
    var c = new Circle({x:0, y:0}, 2.0);
    Circle.prototype = {
    constructor: Circle,
    area: function() { return Math.Pi*this.radius*this.radius;}
    };
    c.area(); // uncaught Typeerror
    ```

  - 생성자가 기존에 가지고 있던 프로토타입 객체에 프로퍼티를 추가한 경우 생성자와 인스턴스 사이의 견결 고리가 끊기지 않는다.

    ```js
    function Circle(center, radius) {
      this.center = center;
      this.radius = radius;
    }
    var c = new Circle({ x: 0, y: 0 }, 2.0);
    Circle.prototype.area = function () {
      return Math.PI * this.radius * this.radius;
    };
    c.area(); // 12.56637
    ```

### 9.2.6 프로토타입 확인

---

- instanceof 연산자

  ```JS
  function F() {};
  var obj = new F();
  console.log(obj instanceof F);
  console.log(obj instanceof Object);
  ```

- isPrototypeOf Method

  ```JS
  function F() {};
  var obj = new F();
  console.log(F.prototype.isPrototypeOf(obj));
  console.log(Object.prototype.isPrototypeOf(obj));
  ```

### 9.2.7 Object.prototype

- Object.prototype의 메서든느 모든ㅈ내장 객체로 전파되며 모든 인스턴스에서 사용할 수 있다.
- 모든 객체는 Object.prototype으로부터 상속 받기 때문
- Object 생성자 : 빈 생성자 생성

  ```JS
  var obj = new Object();
  // {} 생성
  ```

- Object 생성자의 프로퍼티와 메서드
  - 프로퍼티 : prototype
  - 메서드 :
- Object.prototype의 메서드
  - 메서드 :

### 9.2.8 Object.create로 객체 생성하기

---

Object.create 메서드를 사용하면 명시적으로 프로토타입을 지정해서 객체 생성이 가능하다.

- parametere
  1. 생성할 객체의 프로토타입
  2. 생성할 객체의 프로퍼티

---

```JS
var person1 = {
  name: "TOM",
  sayHello: function() {
    console.log("Hello! "+this.name);
  }
}
var person2 = Object.create(person1);
person2.name = "Huck";
person2.sayHello();
```

## 9.3 접근자 프로퍼티

---

### 9.3.1 프로퍼티 종류

1. 데이터 프로퍼티 : 값 저장 위한 프로퍼티
2. 접근자 프로퍼티 : 값이 없고 프로퍼티를 일거나 쓸 때 호출하는 함수를 값 대신에 지정할 수 있는 프로퍼티

---

### 9.3.2 접근자 프로퍼티

- 접근자 : 객체 지향 프로그래밍에서 객체가 가진 프로퍼티 값을 객체 바깥에서 읽거나 쓸 수 있도록 제공하는 메서드

  - 세터 함수 : 프로퍼티 쓸 때의 처리 담당
  - 게터 함수 : 프로퍼티 읽을 때의 처리 담당

    ```JS
    ver person = {
      _name : "Tom",
      get name(){
        return this._name;
      }
      set name(value){
        this._name = value;
      }
    };
    console.log(person.name);
    person.name = "tommy";
    console.log(person.name);
    ```

- 접근자 프로퍼티 또한 delete 함수를 통해 삭제 할 수 있다.

  ```JS
  delete person.name;
  ```

## 9.4 프로퍼티 속성

---

### 9.4.1 프로퍼티 속성

1. Writable
2. Enumerable
3. Configurable

- 데이터 프로퍼티

  - 값
  - 쓰기 가능
  - 열거 가능
  - 재정의 가능

- 접근자 프로퍼티

  - 읽기(getter)
  - 쓰기(setter)
  - 열거 가능
  - 재정의 가능

- 새로운 프로퍼티를 추가하면 기본 속성은 세가지 세부 속성 모두 true

### 9.4.2 프로퍼티 디스크립터와 프로퍼티를 읽고 쓰는 메소드

- 프로퍼티 속성은 프로퍼티 디스크립터로 설정 가능하다.

- 프로퍼티 디스크립터는 프로퍼티 속성 값을 뜻하는 객체

- 프로퍼티 디스크립터 가져오기 : Object.getOwnPropertyDescriptor

  ```JS
  var tom = {name : "TOM"};
  Object.getOwnPropertyDescriptor(tom, "name");
  ```

- 객체의 프로퍼티 설정하기 : Object.defineProeprty

  ```JS
  var obj = {};
  Object.defineProperty(obj, "name", {
    value: "Tom",
    writable : true,
    enumarable : true,
    configurable : true
  });
  Object.getOwnPropertyDescriptor(obj, "name");
  ```
