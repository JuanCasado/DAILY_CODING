package main
import "fmt"
import "strconv"
import "os"

func claculatePosibilities(message string) int {
        firstZero := message[0] == '0'
        size := len(message)
        switch {
        case size == 1:
                return isValid(message)
        case size == 2:
                if firstZero {
                    return isValid(message)
                }
                return isValid(message) + 1
        default:
                return isValid(message[:1])*claculatePosibilities(message[1:]) + isValid(message[:2])*claculatePosibilities(message[2:])
        }
}

func isValid(messageFragment string) int {
        if messageFragment[0] == '0' {
            return 0
        }
        value, err := strconv.ParseInt(messageFragment, 10, 64)
        if err != nil {
                return 0
        }
        if (value >= 0) && (value <= 26) {
                return 1
        }
        return 0
}

func main() {
    if len(os.Args) > 0 {
        fmt.Println(claculatePosibilities(os.Args[1]))
    } else {
        fmt.Println("Input is missing");
    }
}