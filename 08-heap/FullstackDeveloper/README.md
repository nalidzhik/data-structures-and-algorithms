# Fullstack developer

https://www.hackerrank.com/contests/sda-hw-8-2021/challenges/fullstack-developer

Петко е супер щастлив, че започва нова работа като програмист в нова и изгравяща фирма. Уловката е, че Петко е единственият програмист, а работа има много. Тя е разделена на N отделни задачи, като всяка една ще може да бъде започната във време t[i] и ще отнеме време f[i], където i е номера на задачата. Петко, като всеки един човек винаги ще започне най-бързата за свършване задача и ще я довърши изцяло преди да започне нова. В същият момент като приключи задача той започва новата без почивка.

Забележка: Ако в един момент има повече от 1 задача, която е най-бърза за приключване, Петко иска да започне с тази, която е била подадена първа (тази която е била най-рано във входа).

### Input Format

На първия ред на стандартния вход ще получите броя на задачите N На следвашите N реда ще получите по две числа t[i] и f[i], съответно времето от което нататък включително ще може да се започне задачата и колко време ще отнеме за изпълнение i-тата задача(i e номера на реда, като номерацията започава от 0)

### Constraints

1 <= N <= 10^5 1 <= t,f <= 10^9

### Output Format

На стандартния изход изкарайте реда, в който задачите ще се свършат задачите от Петко. Индексите в реда на изпълнение разделени с интервал.

### Sample Input 0

```
4
3 3
2 4
1 2
7 1
```

### Sample Output 0

```
2 0 1 3
```

### Explanation 0

В момент едно единствеанта задача, която може да се започне е третата задача(тази с индекс 2), така че Петко ще започне нея. Тя ще отнеме време 2 и ще бъде готова във време 3. Във време 3 има две задачи, които ще могат да се започнат(тези с индекс 0 и 1). Петко ще започне задачата с индекс 0 понеже тя ще отнеме по-малко време за свършване(3<4). Във време 6 той ще е готов със задачата и само една задача ще бъде възможно да се започне тогава(тази с индекс 1). Тя ще бъде готова във време 10 и в този момент ще бъде започната последната останала задача. Реда на изпълнение на задачаите е: 2 0 1 3