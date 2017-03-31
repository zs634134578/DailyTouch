package main

import "fmt"

type person struct {
    name string
    age int
}

func main() {
    fmt.Println(person{"Bob", 20})
    fmt.Println(person{name: "Alice", age: 30})
    fmt.Println(person{name: "Fred"})
    fmt.Println(&person{name: "Ann", age: 40})

    var s person = person{name: "Sean", age: 50}
    fmt.Println(s.name)

    var sp *person = &s
    fmt.Println(sp.age)

    sp.age = 51
    fmt.Println(sp.age)

    var sp2 * person;
    if sp2 == nil {
        fmt.Println("pointer's init value is nil")
    }
    sp2 = &person{"Bob", 21}
    fmt.Println(sp2)
}
