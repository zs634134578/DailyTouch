package main

import (
    "crypto/sha512"
    "fmt"
    "hash"
)

func main() {
    var hasher hash.Hash
    if hasher == nil {
        fmt.Printf("haha %x\n", hasher.Size())
    }
    hasher = sha512.New384()
    hasher.Write([]byte("13572468.123"))
    fmt.Printf("%x", hasher.Sum(nil))
}
