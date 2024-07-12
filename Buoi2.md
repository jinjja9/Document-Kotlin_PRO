#  [KOTLIN] BUỔI 2: Class in Kotlin 

***
## I. Class

### 1. Class
- Trong Kotlin, một **class** (lớp) là một khuôn mẫu dùng để tạo các đối tượng. Một lớp có thể chứa các thuộc tính (properties) và phương thức (functions) để mô tả các hành vi và trạng thái của đối tượng.
```
class Student {
    // thuoc tinh
    var name = "Ten"
    var age = "tuoi"

    // phuong thuc
    fun showInfo(){
        println(this.name)
        println(this.age)
    }
}
```
```
fun main() {
    var student=Student()
    student.showInfo()
}
```
```
Ten
tuoi
```

### 2: Access modifier
- Trong Kotlin, access modifier (bộ điều khiển truy cập) được sử dụng để kiểm soát mức độ truy cập của các lớp, phương thức và thuộc tính. Kotlin hỗ trợ bốn loại access modifier:

    ***public (mặc định)*** : là mặc định nếu không chỉ định access modifier.

    ***private***

    ***protected***

    ***internal***
#### 2.1: public

-   Các thành viên được khai báo là public có thể truy cập từ bất kỳ đâu.
- Trong Kotlin, nếu không chỉ định rõ access modifier, thì mặc định là public.

```
class Student {
    public var name: String = "Hieu"

    public fun showName() {
        println(name)
    }
}

fun main() {
    val example = Student()
    example.name = "Hoang"
    example.showName()
}
```
```
Hoang
```
#### 2.2: private

- Các thành viên được khai báo là private chỉ có thể truy cập bên trong lớp chứa nó.

```
class Student {
    private var name: String = "Hieu"

    public fun showName() {
        println(name)
    }
}

fun main() {
    val example = Student()
    //example.name = "Hoang" Lỗi: không thể truy cập 'name' vì nó là private
    example.showName()
}
```

#### 2.3: protected

- **protected** cho phép truy cập các thành viên từ lớp chứa nó và các lớp con (subclass).

- **protected** không cho phép truy cập từ bên ngoài lớp đó và các lớp con của nó.


- Trong Kotlin, từ khóa open được sử dụng để cho phép một lớp có thể được kế thừa. Mặc định, các lớp trong Kotlin là final, nghĩa là chúng không thể bị kế thừa. Để cho phép một lớp có thể được mở rộng, bạn cần khai báo lớp đó là open.

-   Lớp **open**: Khi bạn khai báo một lớp là open, bạn cho phép các lớp khác có thể kế thừa từ lớp này.
-   Lớp **final** (mặc định): Lớp mặc định trong Kotlin là final, có nghĩa là chúng không thể bị kế thừa.

#### 2.4: internal

- **internal** cho phép truy cập các thành viên từ bất kỳ đâu trong cùng một module.
- Module là một tập hợp các file Kotlin được biên dịch cùng nhau.
(e chưa hiểu lắm về internal:(( )))
```
internal class InternalExample {
    internal var internalVar: String = "Internal Variable"

    internal fun showInternalVar() {
        println(internalVar)
    }
}

fun main() {
    val example = InternalExample()
    example.internalVar = "New Internal Value"
    example.showInternalVar()  // Output: New Internal Value
}

```


### 3. Constructor
- Trong Kotlin, constructor (hàm khởi tạo) được sử dụng để khởi tạo đối tượng của một lớp. Kotlin hỗ trợ cả primary constructor và secondary constructor, cho phép bạn linh hoạt trong việc khởi tạo đối tượng.

#### 3.1: Primary Constructor
- Primary constructor được khai báo ngay trong phần khai báo lớp. Nó có thể chứa các tham số và các thuộc tính có thể được khởi tạo trực tiếp từ các tham số này.

```
class Student (var name:String, var age:Int ) {
    fun showInfo(){
        println("Hello, my name is $name, I'm $age years old")
    }
}

fun main() {
    // Sử dụng primary constructor
    val student =Student("Hieu",18)
    student.showInfo()
}
```

-  Trong Kotlin, khối **init** là một khối khởi tạo (initialization block) được sử dụng để thêm logic khởi tạo cho một lớp. Nó được chạy ngay sau khi primary constructor được gọi. Khối **init** cho phép bạn thực hiện các thao tác khởi tạo phức tạp mà không cần phải đặt tất cả trong constructor.


 ```
class Student (var name:String="", var age:Int=0 ) {
        init {
            name="Hoang Hieu"
            age =18
        }
    fun showInfo()
    {
        println(this.name)
        println(this.age)
    }
fun main() {
    val student =Student()
    student.showInfo()
}
}
```
```
Hoang Hieu
18
```

#### 3.2: Secondary Constructor
- Secondary constructor được khai báo bên trong thân của lớp và có thể được sử dụng để thêm logic khởi tạo hoặc khi bạn cần các constructor khác nhau.

```
class Student(var name: String, var age: Int) {  // Primary constructor
    var address: String = "Lao Cai"

    // Secondary constructor
    constructor(name: String, age: Int, address: String) : this(name, age) {
        this.address = address
    }

    fun showInfo() {
        println("Tên: $name")
        println("Tuổi: $age")
        println("Địa chỉ: $address")
    }
}


fun main() {
    val student = Student("Hieu", 18)
    student.showInfo()

    val student2 = Student("Hieu", 18, "NamDInh")
    student2.showInfo()
}
```

```
Tên: Hieu
Tuổi: 18
Địa chỉ: Lao Cai
Tên: Hieu
Tuổi: 18
Địa chỉ: NamDInh
```

### 4: Init block

- Trong Kotlin, khối **init** (viết tắt của "initialization") là một phần của lớp được sử dụng để thực hiện các thao tác khởi tạo mà không thể thực hiện trong phần khai báo thuộc tính. Các khối init được chạy mỗi khi một đối tượng của lớp được tạo, ngay sau khi các constructor chính được gọi.

**Cú pháp của khối init:** Có thể khai báo một hoặc nhiều khối init trong một lớp. Các khối init sẽ được chạy theo thứ tự chúng xuất hiện trong mã nguồn.

```
class Student (var name:String="", var age:Int=0 ) {
       init {
           name="Hoang Hieu"
           age =18
       }
   fun showInfo()
   {
       println(this.name)
       println(this.age)
   }
fun main() {
   val student =Student()
   student.showInfo()
}
}
```

```
class Student(val name: String) {
    var age: Int = 0

    // Khối init
    init {
        println("Init block called")
    }

    // Secondary constructor
    constructor(name: String, age: Int) : this(name) {
        this.age = age
        println("Secondary constructor called")
    }

    fun showInfo() {
        println("Name: $name, Age: $age")
    }
}

fun main() {
    val student1 = Student("Hieu")
    student1.showInfo()  // Output: Name: Hieu, Age: 0

    val student2 = Student("Hieu", 18)
    student2.showInfo()  // Output: Name: Hieu, Age: 18
}

```

## 5: Class members
- Trong Kotlin, các thành viên của một lớp (class members) bao gồm các thuộc tính (properties), phương thức (methods), khối init, các hàm thành viên (member functions), các lớp lồng nhau (nested classes), và các đối tượng lồng nhau (nested objects). 

#### 5.1 Properties 
- Thuộc tính là các biến được khai báo bên trong lớp. Chúng có thể là val (immutable) hoặc var (mutable).


#### 5.2 Methods 
- Phương thức là các hàm được định nghĩa bên trong lớp. Chúng có thể truy cập và thao tác với các thuộc tính của lớp.


#### 5.3: Khối init
- Khối init được sử dụng để thực hiện các thao tác khởi tạo bổ sung.


#### 5.4: Functions
```
class Calculator {
    fun add(a: Int, b: Int): Int {
        return a + b
    }
}
```

#### 5.5: Lớp lồng nhau (Nested Classes)
- Lớp lồng nhau là các lớp được định nghĩa bên trong một lớp khác. Chúng có thể là inner class hoặc nested class.

- **Static Nested Class**: 
    - Được khai báo với từ khóa static.
    - Không thể truy cập trực tiếp các thành viên không tĩnh của lớp bao ngoài.
    - Được truy cập mà không cần tạo một thể hiện của lớp bao ngoài.

- **Non-static Inner Class**
    - Không được khai báo với từ khóa static.
    - Có thể truy cập trực tiếp các thành viên của lớp bao ngoài.
    - Phải tạo một thể hiện của lớp bao ngoài trước khi tạo thể hiện của inner class.
```
class Outer {
    // Nested class
    class Nested {
        fun nestedFunction() {
            println("Nested class function")
        }
    }

    // Inner class
    inner class Inner {
        fun innerFunction() {
            println("Inner class function")
        }
    }
}

fun main() {
    //  Nested class
    val nested = Outer.Nested()
    nested.nestedFunction()  // Kết quả: Nested class function

    // Inner class
    val outer = Outer()
    val inner = outer.Inner()
    inner.innerFunction()  // Kết quả: Inner class function
}

```

#### 5.6: Đối tượng lồng nhau (Nested Objects)
- Đối tượng lồng nhau là các đối tượng được định nghĩa bên trong một lớp khác. Chúng thường được sử dụng để tạo singleton.

```
class Outer {
    object name {
        fun show() {
            println("Hoang Hieu")
        }
    }
}

fun main() {
    // Gọi phương thức từ đối tượng name
    Outer.name.show()  // Kết quả: Hoang Hieu
}

```

#### 5.7: Getter và Setter

- Trong Kotlin,  có thể định nghĩa các thuộc tính (properties) của một lớp và Kotlin sẽ tự động tạo các getter và setter tương ứng (nếu cần) cho thuộc tính đó. Tuy nhiên, bạn cũng có thể tùy chỉnh cách getter và setter được tạo bằng cách sử dụng các thuộc tính có chứa (properties with backing fields) hoặc các phương thức getter và setter tường minh. Dưới đây là một số cách bạn có thể làm điều đó:

**Getter và Setter mặc định**
- Khi  định nghĩa một thuộc tính trong Kotlin, getter và setter sẽ được tạo mặc định nếu bạn không định nghĩa một cách tường minh.

```
class Example {
    var name: String = "Hieu"  // Mặc định sẽ có getter và setter
}
```
Khi sử dụng:

```
class Example {
    var name: String = "Hieu"  // Mặc định sẽ có getter và setter
}

fun main() {
    val obj = Example()
    println(obj.name)  // Gọi getter: In ra "Hieu"
    obj.name = "Hoang"  // Gọi setter
    println(obj.name)  // Gọi lại getter: In ra "Hoang"
}

```

**Custom Getter và Setter**

- Bạn có thể tùy chỉnh hành vi của getter và setter bằng cách sử dụng thuộc tính có chứa (backing field) và các phương thức getter và setter tường minh.

```
class Example {
    // Khai báo backing field
    private var _value: Int = 0

    // Custom getter
    var value: Int
        get() {
            println("Getting value")
            return _value
        }
        // Custom setter
        set(newValue) {
            println("Setting value to $newValue")
            _value = newValue
        }
}
fun main() {
    val obj = Example()
    println(obj.value)  // In ra "Getting value" và "0"
    obj.value = 10  // In ra "Setting value to 10"
    println(obj.value)  // In ra "Getting value" và "10"
}
```

### 6: Companion object

Trong Kotlin, companion object là một cơ chế cho phép bạn định nghĩa các thành viên (properties, methods) trong phạm vi của một đối tượng đặc biệt gọi là companion object của lớp đó. Các thành viên trong companion object có thể được truy cập trực tiếp thông qua tên của lớp mà không cần tạo một thể hiện của lớp đó.


Để khai báo một companion object trong Kotlin, bạn sử dụng từ khóa companion object sau định nghĩa lớp.

```
class ConMeo()
{
    companion object{
        fun tiengKeu()
        {
            println("go go")
        }
    }
}
fun main()
{
    ConMeo.Companion.tiengKeu()
}
```

**Sử dụng Companion Object**

-   Companion object thường được sử dụng cho các hằng số, phương thức tiện ích, hàm factory, hoặc các tác vụ liên quan đến lớp mà không cần tạo một thể hiện của lớp đó.

-   Khi bạn cần các hằng số hoặc phương thức được chia sẻ chung giữa các đối tượng của lớp, companion object là một lựa chọn lý tưởng.

## II. Special Class
### 1: Data class

// Không sử dụng var, mà nên sử dụng val ở khai báo 

Trong Kotlin, **data class** là một cú pháp đặc biệt để định nghĩa một lớp dùng để lưu trữ dữ liệu (data holder). Kotlin sẽ tự động tạo các thành viên của lớp như các trường (properties), phương thức **equals()**, **hashCode()**, **toString()**, **copy()** và các hàm tạo (constructor) từ các thuộc tính được khai báo trong primary constructor của **data class**.

**Cú pháp của Data Class**

Để khai báo một data class trong Kotlin, bạn sử dụng từ khóa data trước định nghĩa lớp.

```
data class User(val name: String, val age: Int)
```
**Điểm quan trọng của Data Class**

-   **Các thành viên được tạo tự động**: Kotlin tự động tạo các phương thức equals(), hashCode(), toString() và copy() dựa trên các thuộc tính đã được khai báo trong primary constructor.

-   **Immutable by default**: Các thuộc tính trong primary constructor của data class có thể là val (immutable) hoặc var (mutable).

-   **Phương thức componentN()**: Kotlin tự động tạo các phương thức componentN() cho các thuộc tính của data class, giúp bạn sử dụng cú pháp destructuring.

-   **Copy function**: Phương thức copy() được tạo ra để tạo một bản sao của đối tượng, cho phép bạn thay đổi một số thuộc tính mà không cần thay đổi các thuộc tính khác.

```
import java.util.Objects;

public class User {
    private String name;
    private int age;

    // Constructor
    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Getter và Setter (nếu cần)

    // equals() method
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return age == user.age && Objects.equals(name, user.name);
    }

    // hashCode() method
    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    // toString() method
    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    // copy() method
    public User copy() {
        return new User(name, age);
    }

    public static void main(String[] args) {
        // Creating an instance of User
        User user1 = new User("Alice", 30);

        // Using overridden methods
        System.out.println(user1);  // toString() method

        // Creating a copy using copy() method
        User user2 = user1.copy();
        System.out.println("Copy: " + user2);  // toString() method

        // Testing equals() method
        User user3 = new User("Alice", 30);
        System.out.println("user1 equals user3? " + user1.equals(user3));  // equals() method
    }
}

```

```
data class User(val name: String, val age: Int)

fun main() {
    // Khởi tạo một đối tượng User
    val user1 = User("Alice", 30)

    // In ra thông tin của user1 sử dụng phương thức toString() được tạo tự động
    println(user1)  // Output: User(name=Alice, age=30)

    // Tạo một bản sao của user1 với tuổi được thay đổi
    val user2 = user1.copy(age = 32)

    // In ra thông tin của user2
    println(user2)  // Output: User(name=Alice, age=32)

    // Destructuring
    val (name, age) = user1
    println("Name: $name, Age: $age")  // Output: Name: Alice, Age: 30
}

```
    
- Trong Kotlin, destructuring là một tính năng cho phép bạn trích xuất các thành phần (elements) từ một cấu trúc dữ liệu phức tạp như một đối tượng, một mảng, hoặc một bộ giá trị, và gán chúng vào các biến riêng lẻ một cách dễ dàng.

- **Destructuring với Data Class**
Khi bạn khai báo một data class trong Kotlin, Kotlin sẽ tự động tạo các phương thức componentN() tương ứng với số lượng thuộc tính trong data class. Điều này cho phép bạn sử dụng destructuring để trích xuất các thuộc tính ra khỏi đối tượng và gán chúng vào các biến.

### 2: Enum Class

- Trong Kotlin, **enum class** là một kiểu dữ liệu đặc biệt cho phép bạn định nghĩa một nhóm hằng số có giới hạn (enumerated constants). Các enum class trong Kotlin có thể chứa các hằng số, phương thức, và thuộc tính.

**Cú pháp của Enum Class**

Để khai báo một enum class trong Kotlin, bạn sử dụng từ khóa enum class sau đó liệt kê các hằng số của enum class bên trong.

```
enum class Direction {
    NORTH, SOUTH, EAST, WEST
}
```

**Các thành phần của Enum Class**
- Hằng số (enum constants): Đây là các giá trị cố định mà enum class có thể nhận. Trong ví dụ trên, NORTH, SOUTH, EAST, và WEST là các hằng số của enum class Direction.

```
enum class Direction {
    NORTH, SOUTH, EAST, WEST;

    fun printDirection() {
        println("Direction: $this")
    }
}
```

**Sử dụng Enum Class**

Khi bạn khai báo một enum class, Kotlin sẽ tự động tạo một đối tượng enum cho mỗi hằng số trong enum class đó. Bạn có thể sử dụng các đối tượng enum này để thực hiện so sánh và truy cập các thuộc tính hoặc phương thức của enum class.

```
enum class Direction {
    NORTH, SOUTH, EAST, WEST;

    fun printDirection() {
        println("Direction: $this")
    }
}

fun main() {
    val currentDirection = Direction.NORTH
    println("Current direction: $currentDirection")  // Output: Current direction: NORTH

    currentDirection.printDirection()  // Output: Direction: NORTH
}
```

**Lấy giá trị của Enum Constant**
Bạn có thể lấy giá trị của enum constant dựa trên tên của nó bằng cách sử dụng phương thức **valueOf()**.
```
val direction = Direction.valueOf("NORTH")
println("Direction found: $direction")  // Output: Direction found: NORTH

```

**sử dụng constructor để khai báo các thuộc tính**

```
enum class RGBColor(val r: Int, val g: Int, val b: Int) {
    RED(255, 0, 0),
    GREEN(0, 255, 0),
    BLUE(0, 0, 255),
    WHITE(255, 255, 255),
    BLACK(0, 0, 0);

    fun rgb(): String {
        return "RGB($r, $g, $b)"
    }
}

fun main() {

   // val redColor = RGBColor.RED
   // println("RGB value of ${redColor.name} is ${redColor.rgb()}")  // Output: RGB value of RED is RGB(255, 0, 0)

    for(item in RGBColor.values())
        println("RGB value of $item is ${item.rgb()}")
}
```

### 3: Sealed class
Trong Kotlin, **sealed class** là một loại lớp đặc biệt cho phép bạn giới hạn một tập hợp các lớp con có thể kế thừa từ nó. Điều này giúp bạn kiểm soát tốt hơn về hệ thống phân cấp lớp (class hierarchy) và thường được sử dụng khi bạn có một tập hợp các giá trị hoặc trường hợp (cases) mà bạn biết trước và không muốn mở rộng thêm ngoài các lớp con đã xác định.

**Cú pháp và cách sử dụng**
Sealed class được khai báo bằng từ khóa **sealed**. Các lớp con của sealed class phải được khai báo cùng tệp (file) với sealed class.
```
sealed class Shape {
    data class Circle(val radius: Double) : Shape()
    data class Rectangle(val width: Double, val height: Double) : Shape()
    object NotAShape : Shape()
}

fun describeShape(shape: Shape): String {
    return when (shape) {
        is Shape.Circle -> "A circle with radius ${shape.radius}"
        is Shape.Rectangle -> "A rectangle with width ${shape.width} and height ${shape.height}"
        Shape.NotAShape -> "Not a shape"
    }
}

fun main() {
    val circle = Shape.Circle(5.0)
    val rectangle = Shape.Rectangle(4.0, 6.0)
    val notAShape = Shape.NotAShape

    println(describeShape(circle))      // Output: A circle with radius 5.0
    println(describeShape(rectangle))   // Output: A rectangle with width 4.0 and height 6.0
    println(describeShape(notAShape))   // Output: Not a shape
}
```

**Lợi ích của Sealed Class**
- **An toàn hơn**: Bởi vì tất cả các lớp con phải được khai báo trong cùng một tệp, trình biên dịch có thể kiểm tra và đảm bảo rằng tất cả các trường hợp đã được xử lý, điều này làm cho mã của bạn an toàn hơn.

- **Rõ ràng và dễ hiểu**: Sealed class giúp cho cấu trúc phân cấp lớp của bạn rõ ràng hơn, vì tất cả các lớp con được định nghĩa ở cùng một nơi.

- **Hỗ trợ tốt hơn cho biểu thức when**: Khi bạn sử dụng sealed class với biểu thức when, bạn không cần phải thêm nhánh else vì trình biên dịch biết rằng bạn đã xử lý tất cả các lớp con có thể có.