#  [KOTLIN] BUỔI 1: MỞ ĐẦU

***
## 1. Biến, kiểu dữ liệu
### 1.1: Khai báo biến

* **val**: Dùng để khai báo biến không thay đổi giá trị (immutable).

* **var**: Dùng để khai báo biến có thể thay đổi giá trị (mutable).

Ví dụ:
```
fun main()
{
    val Name:String = "Hoang Hieu" // Khai bao kieu du lien
    var name ="Hoang Trung Hieu"   // Khong can khai bao kieu du lieu
    Name = "Trung" // Loi
    name = "Trung" // khong loi
    println(Name)
    println(name)
}
```
### 1.2: Kiểu dữ liệu cơ bản

Kotlin hỗ trợ các kiểu dữ liệu cơ bản như sau:

- Int: Số nguyên.
- Long: Số nguyên lớn.
- Double: Số thực lớn.
- Float: Số thực .
- Boolean: Giá trị logic (true hoặc false).
- Char: Ký tự.
- String: Chuỗi ký tự.

```
fun main() {
    val age = 10 //INT
    val number = 1000L //LONG
    val pi = 3.14 // FLOAT
    val listString = """
        Hoang
        Trung
        Hieu
    """
    println(listString)
    ///....
}
```
## 2.Câu lệnh rẽ nhánh

### 2.1: If
```
fun main() {
    val number = 10
    if (number > 0) {
        println("$number is positive.")
    }
}

```
### 2.2: If-else
```
fun main() {
    val number = -5
    if (number > 0) {
        println("$number is positive.")
    } else {
        println("$number is non-positive.")
    }
}

```

### 2.3: When 
- Câu lệnh when tương tự như switch trong các ngôn ngữ khác

```
fun main()
{
    val n=10
    when(n)
    {
        in 1..5 ->{
            println("TB")
        }
        in 6..8 -> {
            println("Kha")
        }
        in 9..10 ->
        {
            println("Gioi")
        }

        else ->
        {
            println("SOS")
        }
    }
}
```

## 3. Vòng lặp
### 3.1: FOR
```
fun main() {
    var range = 1..5
    for (i in 1..5) // 1 2 3 4 5
        print("$i ")
    println()

    for (i in range) // 1 2 3 4 5  (Range)
        print("$i ")
    println()

    for (i in 1 until 5) // 1 2 3 4
        print("$i ")
    println()

    for (i in 5 downTo 1) // 5 4 3 2 1
        print("$i ")
    println()

    for (i in 1..5 step 2) // 1 3 5
        print("$i ")
    println()
}
```

### 3.2 While
- Tương tự các ngôn ngữ lập trình khác
```
fun main()
{
    var n=0
    while(n<10)
    {
        n++;
        print("$n ")
    }
}
```

### 3.3: do .. while
- Tương tự các ngôn ngữ lập trình khác
```
fun main() {
    var n = 0
    do {
        n++;
        print("$n ")
    } while (n < 10)
}
```

### 3.4 loop**
- Nhãn (label): Nhãn là một cách để đặt tên cho các khối lệnh hoặc vòng lặp trong Kotlin. Bạn có thể đặt nhãn bằng cách thêm tên nhãn và dấu @ trước khối lệnh hoặc vòng lặp. Trong ví dụ này, nhãn loop@ được đặt trước vòng lặp for.


- break có nhãn: break có nhãn sẽ thoát ra khỏi vòng lặp được gắn nhãn cụ thể đó. Thay vì chỉ thoát ra khỏi vòng lặp bên trong, nó sẽ thoát ra khỏi vòng lặp mà nhãn được gắn vào


```
fun main() {
    // loop
    loop@ for(i in 1..5)
    {
        for(j in 1 .. 5)
        {
            println("i = $i || j= $j ")
            if(j>i)  // Thoat ra phong for ngoai
                break@loop
        }
    }
}
```

## 4: Colection trong Kotlin
- Kotlin cung cấp một số loại collections như List, Set và Map, mỗi loại có các đặc điểm và cách sử dụng riêng biệt. Các collections có thể là mutable (có thể thay đổi) hoặc immutable (không thể thay đổi).

### 4.1: List

- **List** là một collection có thứ tự, cho phép chứa các phần tử trùng lặp.
- **Immutable List**: Không thể thay đổi sau khi được khởi tạo.
- **Mutable List**: Có thể thay đổi sau khi được khởi tạo (thêm, sửa, xóa phần tử).

```
fun main() {
    // Immutable List
    val list= listOf("haha","hihi","hoho")
    println(list)

    //Mutable List
    val list1= mutableListOf("hehe")
    list1.add("keke")
    println(list1)

}
```
```
[haha, hihi, hoho]
[hehe, keke]
```

### 4.2: Set

- **Set** là một collection không có thứ tự, không cho phép chứa các phần tử trùng lặp.
- **Immutable Set**: Không thể thay đổi sau khi được khởi tạo.
- **Mutable Set**: Có thể thay đổi sau khi được khởi tạo.
```
fun main() {
    // Immutable Set
    val set= setOf("haha","hihi","hoho")
    println(set)

    //Mutable Set
    var set1= mutableSetOf("hehe")
    set1.add("keke")
    println(set1)

}
```

```
[haha, hihi, hoho]
[hehe, keke]
```

### 4.3: Map

- **Map** là một collection chứa các cặp key-value (khóa-giá trị), mỗi key chỉ ánh xạ tới một value.
- **Immutable Map**: Không thể thay đổi sau khi được khởi tạo.
- **Mutable Map**: Có thể thay đổi sau khi được khởi tạo.

```
fun main() {
    // Immutable Map
    val map= mapOf(1 to "haha",2 to "hihi",3 to "hoho") //val map= mapOf<Int,String>
    println(map)

    //Mutable Map
    var map1= mutableMapOf(1 to "hehe")
    map1[2]="keke"
    println(map1)

}
```

```
{1=haha, 2=hihi, 3=hoho}
{1=hehe, 2=keke}
```

## 5. Null safety

-Null safety (an toàn với giá trị null) là một trong những tính năng quan trọng của Kotlin, giúp ngăn chặn lỗi NullPointerException (NPE) - một lỗi phổ biến trong các ngôn ngữ lập trình như Java. Kotlin đảm bảo null safety bằng cách phân biệt rõ ràng giữa các kiểu có thể chứa giá trị null (nullable types) và các kiểu không thể chứa giá trị null (non-nullable types).

### 5.1: Nullable Types và Non-Nullable Types

Trong Kotlin, một biến không thể chứa giá trị null trừ khi được khai báo rõ ràng là nullable. Cú pháp sử dụng dấu ? để khai báo một biến có thể chứa giá trị null.

**Non-Nullable Type**

```
fun main() {
    var nonNullableString: String = "haha, hehe"
    // nonNullableString = null // Lỗi: Null can not be a value of a non-null type String
}
```

**Nullable Type**

```
fun main() {
    var nullableString: String? = "haha, hehe"
    nullableString = null // Không có lỗi

}
```

### 5.2: Safe Call Operator (?.)
- Safe call operator được sử dụng để truy cập các thuộc tính hoặc phương thức của một đối tượng có thể là null mà không gây ra NullPointerException. Nếu đối tượng là null, biểu thức sẽ trả về null thay vì gây ra lỗi.

```
val length: Int? = nullableString?.length
println(length) // In ra: null (vì nullableString là null)

```
