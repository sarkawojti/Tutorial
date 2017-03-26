import scala.io.StdIn.readInt

class TicTacToe
{
    var board = Array(" ", " ", " ", " ", " ", " ", " ", " ", " ")
    var cross_move : Boolean = false

    def play() =
    {
        var isNotEnd : Boolean = true
        while(isNotEnd)
        {
            showBoard
            println()
            user_move
            println()
            if(isWin)
            {
                isNotEnd = false
                println("Koniec gry. Wygrales")
            }
            if(isPat)
            {
                isNotEnd = false
                println("Koniec gry. Remis")
            }
        }
    }

  def user_move()
  {
    var index : Int = 0
    var not_correct_value : Boolean = true
    while(not_correct_value)
    {
      if (cross_move) {
        print("Podaj gdzie wstawic krzyzyk [zakres 1-9]: ")
      }
      else {
        print("Podaj gdzie wstawic kolko [zakres 1-9]: ")
      }
      index = readInt()
      index = index - 1
      if ((8 < index) || (index < 0) || board(index) != " ")
      {
        print("Podales zla wartosc. ")
      }
      else
      {
        not_correct_value = false
      }
    }
    if(cross_move)
    {
      board(index) = "X"
      cross_move = false
    }
    else
    {
      board(index) = "O"
      cross_move = true
    }
  }

    def isPat() : Boolean =
    {
        for( i <- 0 to 8)
        {
            if(" " == board(i))
            {
                return false
            }
        }
        return true
    }

    def isWin() : Boolean =
    {
        if(board(0) != " " && board(0) == board(1) && board(0) == board(2))
          return true;
        if(board(3) != " " && board(3) == board(4) && board(3) == board(5))
          return true;
        if(board(6) != " " && board(6) == board(7) && board(6) == board(8))
          return true;
        if(board(0) != " " && board(0) == board(3) && board(0) == board(6))
          return true;
        if(board(1) != " " && board(1) == board(4) && board(1) == board(7))
          return true;
        if(board(2) != " " && board(2) == board(5) && board(2) == board(8))
          return true;
        if(board(0) != " " && board(0) == board(4) && board(0) == board(8))
          return true;
        if(board(2) != " " && board(2) == board(4) && board(2) == board(6))
          return true;
        return true;
    }

    def showBoard() =
    {
        println(" " + board(0) + " | " + board(1) + " | " + board(2))
        println("---+---+---")
        println(" " + board(3) + " | " + board(4) + " | " + board(5))
        println("---+---+---")
        println(" " + board(6) + " | " + board(7) + " | " + board(8))
    }
}

object TicTacToeGame
{
  def main(args: Array[String]): Unit =
  {
    val game = new TicTacToe()
    game.play
  }
}