#  [KOTLIN] BUỔI 5: OBJECT && CALLBACK

***

## I. Object

Đôi khi bạn cần tạo một đối tượng có sự thay đổi nhỏ so với một lớp nào đó mà không cần phải khai báo 1 subclass mới từ class đó. Kotlin có thể xử lý điều này bằng các **biểu thức đối tượng** `(object expressions)` và **khai báo đối tượng** `(object declarations)`.


### 1. Object expression

`Object expression` tạo những object từ class **ẩn danh** (anonymous class) - class không được khai báo rõ ràng với class declaration(khai báo lớp). Các class này hữu dụng cho mục đích dùng 1 lần. 
Ta có thể định nghĩa chúng từ scratch, kế thừa từ class đã có, hoặc implement interfaces. Thực thể của lớp ẩn danh còn gọi là **anonymous object** bởi chúng được định nghĩa bằng expression, không phải tên.

#### 1.1: Tạo anonymous object từ scratch

- **Object expression** bắt đầu bằng từ khoá `object`.

- Nếu ta chỉ cần 1 object không có bấy kì supertypes nào, viết các thành phần của nó trong dấu ngoặc nhọn sau object:

```kotlin
fun main() {
    val helloWorld = object {
        val hello = "HeLLo"
        val world = "WorLd"
        // biểu thức đối tượng mở rộng Any, vì vậy `override` là bắt buộc trên `toString()`
        override fun toString() = "$hello $world"
    }

    print(helloWorld) // Output: Hello World
}
```

### 1.2: Kế thừa từ supertypes

Để tạo object của anonymous class mà được kế thừa từ 1 type hay nhiều types, cần xác định type đó sau object và dấu “:”. Sau đó implement hoặc override thành phẩn của class nếu ta kế thừa từ nó. 

```kotlin
window.addMouseListener(object : MouseAdapter() {
    override fun mouseClicked(e: MouseEvent) { /*...*/ }

    override fun mouseEntered(e: MouseEvent) { /*...*/ }
})
```

Nếu là 1 supertype có 1 constructor, cần ưu tiên truyền tham số constructor vào trước. Có nhiều supertypes thì có thể xác định bằng comma-delimited list sau dấu “:”. 

```kotlin
open class A(x: Int) {
    open val y: Int = x
}

interface B { /*...*/ }

val ab: A = object : A(1), B {
    override val y = 15
}
```

### 1.3: Sử dụng anonymous object làm kiểu trả về và giá trị

Khi 1 anonymous object được dùng như 1 kiểu của 1 khai báo local hoặc private mà không phải dạng inline (function hoặc property), tất cả thành phẩn của nó được truy cập thông qua function hay property đó: 

```kotlin
class C {
    private fun getObject() = object {
        val x: String = "x"
    }

    fun printX() {
        println(getObject().x)
    }
}
```

Nếu hàm hoặc thuộc tính này là public hoặc private inline, kiểu thực tế của nó là:

-   `Any` nếu đối tượng ẩn danh không có loại cha nào được khai báo.
-   Loại cha được khai báo của đối tượng ẩn danh, nếu chỉ có một loại cha duy nhất.
-   Kiểu được khai báo rõ ràng nếu có nhiều hơn một loại cha được khai báo.

Trong các trường hợp trên, thành phần thêm vào anonymous object sẽ không thể được truy cập. Override các thành phần thì có nếu chúng được khai báo trong kiểu thật sự (actual type) của hàm hay thuộc tính.

```kotlin
interface A {
    fun funFromA() {}
}

interface B

class C {
    // Kiểu trả về là Any; x không thể truy cập
    fun getObject() = object {
        val x: String = "x"
    }

    // Kiểu trả về là A; x không thể truy cập
    fun getObjectA() = object: A {
        override fun funFromA() {}
        val x: String = "x"
    }

    // Kiểu trả về là B; funFromA() và x không thể truy cập
    fun getObjectB(): B = object: A, B { // cần kiểu trả về rõ ràng
        override fun funFromA() {}
        val x: String = "x"
    }
}
```

### 1.4: Truy cập các biến từ anonymous object

Code trong objecto expression có thể truy cập các biến từ phạm vi bao quanh:

```kotlin
fun countClicks(window: JComponent) {
    var clickCount = 0
    var enterCount = 0

    window.addMouseListener(object : MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) {
            clickCount++
        }

        override fun mouseEntered(e: MouseEvent) {
            enterCount++
        }
    })
    // ...
}
```

### 2. Object declaration(Khai báo đối tượng)

Singleton pattern có thể có ích trong các trường hợp, và Kotlin giúp cho việc khai báo singleton dễ dàng hơn:

```kotlin
object DataProviderManager {
    fun registerDataProvider(provider: DataProvider) {
        // ...
    }

    val allDataProviders: Collection<DataProvider>
        get() = // ...
}
```
- Khai báo như trên được gọi là object declaration (khai báo đối tượng), và nó luôn có 1 cái tên theo sau từ khoá object. Giống việc khai báo 1 biến, 1 object declaration không phải là 1 expression, và nó không thể dùng ở vế phải (right-hand side) của một câu lệnh gán (assignment statement).
- Sự khởi tạo của 1 object declaration là thread-safe (an toàn luồng) và được hoàn thành từ lần truy cập đầu tiên.
- Để tham chiếu tới object, ta dùng tên của nó trực tiếp. Ví dụ với object được khai báo ở trên:

```kotlin
DataProviderManager.registerDataProvider(...)
```
Các object cũng có thể có supertypes:

```kotlin
object DefaultListener : MouseAdapter() {
    override fun mouseClicked(e: MouseEvent) { ... }

    override fun mouseEntered(e: MouseEvent) { ... }
}
```
Object decalaration không thể là local (không thể được lồng (nested) trực tiếp bên trong 1 hàm), nhưng chúng có thể được nested bên trong object declaration hoặc non-inner classes khác.

#### 2.1: Data Objects (Đối tượng dữ liệu)

Khi in ra một khai báo đối tượng thông thường trong Kotlin, chuỗi đại diện của nó chứa cả tên và hash của đối tượng:

```kotlin
object MyObject

fun main() {
    println(MyObject) // Output: MyObject@1f32e575
}
```

Giống như các lớp dữ liệu, bạn có thể đánh dấu một khai báo đối tượng với từ khóa data. Điều này yêu cầu trình biên dịch tạo một số hàm cho đối tượng của bạn:

-   `toString()` trả về tên của đối tượng dữ liệu.
-   Cặp hàm `equals()/hashCode()`.

Bạn không thể cung cấp một triển khai tùy chỉnh cho equals hoặc hashCode cho một đối tượng dữ liệu.

Hàm **toString()** của một đối tượng dữ liệu trả về tên của đối tượng:

```kotlin
data object MyDataObject {
    val x: Int = 3
}

fun main() {
    println(MyDataObject) // Output: MyDataObject
}
```

>Hàm equals() cho một đối tượng dữ liệu đảm bảo rằng tất cả các đối tượng có loại của đối tượng dữ liệu của bạn được coi là bằng nhau. Trong hầu hết các trường hợp, bạn sẽ chỉ có một thể hiện duy nhất của đối tượng dữ liệu của bạn tại runtime (sau cùng, một khai báo đối tượng dữ liệu khai báo một singleton). Tuy nhiên, trong trường hợp một đối tượng khác cùng loại được tạo ra tại runtime (ví dụ, bằng cách sử dụng reflection nền tảng với java.lang.reflect hoặc một thư viện tuần tự hóa JVM sử dụng API này), điều này đảm bảo rằng các đối tượng được coi là bằng nhau.

>Đảm bảo rằng bạn chỉ so sánh các đối tượng dữ liệu theo cấu trúc (sử dụng toán tử ==) và không bao giờ bằng tham chiếu (sử dụng toán tử ===). Điều này giúp bạn tránh được các cạm bẫy khi có nhiều hơn một thể hiện của một đối tượng dữ liệu tồn tại tại runtime.

```kotlin
import java.lang.reflect.Constructor

data object MySingleton

fun main() {
    val evilTwin = createInstanceViaReflection()

    println(MySingleton) // Output: MySingleton
    println(evilTwin) // Output: MySingleton

    // Ngay cả khi một thư viện tạo ra một thể hiện thứ hai của MySingleton, phương thức `equals` của nó trả về true:
    println(MySingleton == evilTwin) // Output: true

    // Không so sánh các đối tượng dữ liệu bằng `===`.
    println(MySingleton === evilTwin) // Output: false
}

fun createInstanceViaReflection(): MySingleton {
    // Reflection Kotlin không cho phép khởi tạo các đối tượng dữ liệu.
    // Điều này tạo ra một thể hiện MySingleton mới "bằng cách cưỡng chế" (tức là reflection nền tảng Java)
    // Không tự làm điều này!
    return (MySingleton.javaClass.declaredConstructors[0].apply { isAccessible = true } as Constructor<MySingleton>).newInstance()
}
```
Hàm **hashCode()** được tạo ra có hành vi phù hợp với hàm **equals()**, sao cho tất cả các thể hiện runtime của một đối tượng dữ liệu có cùng một mã băm.


**Khác biệt giữa data object và data class**:
Mặc dù `data object` và `data class` thường được sử dụng cùng nhau và có một số điểm tương đồng, có một số hàm không được tạo ra cho một `data object`:

-   Không có `copy()` function. Vì `data object` được tạo với mục đích singleton, không có hàm `copy()` nào được tạo ra. Nên nó sẽ giới hạn các thực thể của class thành 1 thực thể duy nhất, điều có thể bị phá vỡ bởi việc cho phép các bản sao chép của thực thể được tạo ra.

-   Không có `componentN()` function. Một `data object` không có bất cứ data properties nào. Vì việc cố gắng hủy cấu trúc một đối tượng như vậy mà không có thuộc tính dữ liệu sẽ không có ý nghĩa, không có hàm `componentN()` nào được tạo ra.

**Dùng data object với sealed hierachies**

Việc khai báo data object vô cùng thích hợp với sealed hierachies, như là sealed class hay sealed interface bởi chúng cho phép ta duy trì sự đối xứng với bất cứ data class ta có thể định nghĩa cùng với object. Ví dụ:

```kotlin
sealed interface ReadResult
data class Number(val number: Int) : ReadResult
data class Text(val text: String) : ReadResult
data object EndOfFile : ReadResult

fun main() {
    println(Number(7)) // Number(number=7)
    println(EndOfFile) // EndOfFile
}
```

#### 2.2 Companion object

1 object declaration bên trong class có thể đánh dấu với từ khóa `companion`:

```kotlin
class MyClass {
    companion object Factory {
        fun create(): MyClass = MyClass()
    }
}
```

Các thành phần của `companion object` có thể được gọi đơn giản bằng cách sử dụng tên lớp làm định tính:

```kotlin
val instance = MyClass.create()
```

Tên của companion object có thể lược bỏ, lúc ấy tên `companion` sẽ được sử dụng: 

```kotlin
class MyClass {
    companion object { }
}

val x = MyClass.Companion
```
- Class member có thể truy cập các private member của companion object tương ứng.
- Tên của class được dùng bới chính nó sẽ hoạt động giống như 1 tham chiếu tới companion object của class (dù có tên hay không):

```kotlin
class MyClass1 {
    companion object Named { }
}

val x = MyClass1

class MyClass2 {
    companion object { }
}

val y = MyClass2
```


>Lưu ý dù các thành phần của companion object nhìn có vẻ như các static member trong các ngôn ngữ khác, tại thời điểm runtime chúng vẫn là thành phần thực thể của 1 object thật và có thể, ví dụ, implent interfaces:

```kotlin
interface Factory<T> {
    fun create(): T
}

class MyClass {
    companion object : Factory<MyClass> {
        override fun create(): MyClass = MyClass()
    }
}

val f: Factory<MyClass> = MyClass
```

**Sự khác biệt về semantic (ngữ nghĩa) giữa object expression và declaration.**

> Có 1 khác biệt semantic quan trọng giữa object expression và declaration:

- Object expression được thực thi (và khởi tạo) ngay lập tức khi chúng được dùng (Khi object được khởi tạo).
- Object declaration được khởi tạo `lazily`(khi được gọi tới mới khởi tạo), trong lần truy cập đầu tiên.
- Một companion object được khởi tạo khi class tương ứng được chạy (xử lý) mà match với ngữ nghĩa của 1 Java static initalizer (ngay khi chương trình chạy).

### 3. Hình thái tương đương của object declaration, object expression trong Java.

#### 3.1: Object Declaration

-   Tương đương với anonymous class trong Java:

```kotlin
//Kotlin
interface Printer {
    fun printMessage(message: String)
}

fun main() {
    val printer = object : Printer {
        override fun printMessage(message: String) {
            println(message)
        }
    }

    printer.printMessage("Hello, Kotlin!")
}
```
> Trong ví dụ này, chúng ta định nghĩa một interface Printer với một phương thức printMessage. Sau đó, chúng ta sử dụng Object Expression để tạo một đối tượng ẩn danh thực hiện interface này và gọi phương thức printMessage.

```java
//Java
interface Printer {
    void printMessage(String message);
}

public class Main {
    public static void main(String[] args) {
        Printer printer = new Printer() {
            @Override
            public void printMessage(String message) {
                System.out.println(message);
            }
        };

        printer.printMessage("Hello, Java!");
    }
}

```
>Ví dụ này cũng tương tự như ví dụ trong Kotlin, sử dụng anonymous class để thực hiện interface Printer và gọi phương thức printMessage.

#### 3.2: Object declaration
Trong java, object declaration là singleton pattern:

```kotlin
//Kotlin
object SimpleSingleton {
    var message: String = "Hello, Singleton!"
}

fun main() {
    println(SimpleSingleton.message)  // In ra: Hello, Singleton!
}

```

```java
//java
public class SimpleSingleton {
    private static final SimpleSingleton INSTANCE = new SimpleSingleton();
    public String message = "Hello, Singleton!";

    private SimpleSingleton() {}

    public static SimpleSingleton getInstance() {
        return INSTANCE;
    }

    public static void main(String[] args) {
        SimpleSingleton singleton = SimpleSingleton.getInstance();
        System.out.println(singleton.message);  // In ra: Hello, Singleton!
    }
}

```
Trong các ví dụ này:

-   **Kotlin:** object SimpleSingleton cung cấp một đối tượng singleton với thuộc tính message.
-   **Java:** SimpleSingleton sử dụng Singleton pattern với phương thức getInstance() để cung cấp một đối tượng singleton và thuộc tính message.

## II. Callback