import scala.io.StdIn.readInt

class TicTacToe
{
    var board = Array(" ", " ", " ", " ", " ", " ", " ", " ", " ")
    var cross_move : Boolean = false

    def play() : Unit =
    {
        while(true)
        {
            draw_a_board
            user_move
            if(is_win)
            {
                draw_a_board
                println("Koniec gry. Wygrales")
                return
            }
            if(is_pat)
            {
                draw_a_board
                println("Koniec gry. Remis")
                return
            }
        }
    }

  def get_move() : Int =
  {
      while(true)
        {
          if (cross_move)
          {
            print("Podaj gdzie wstawic krzyzyk [zakres 1-9]: ")
          }
          else
          {
            print("Podaj gdzie wstawic kolko [zakres 1-9]: ")
          }
          var index : Int = readInt() - 1

          if ((8 < index) || (index < 0))
            {
              print("Podales zla wartosc [Z POZA ZAKRESU]. ")
            }
          else if (board(index) != " ")
            {
              print("Podales zla wartosc [POLE JEST JUZ ZAJETE].")
            }
          else
            {
              return index
            }
        }
    return -1
  }
  def user_move()
  {
    var index : Int = get_move

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

    def is_pat() : Boolean =
    {
        for( i <- 0 until board.size)
        {
            if(" " == board(i))
            {
                return false
            }
        }
        return true
    }

    def is_win() : Boolean =
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
        return false;
    }

    def draw_a_board() =
    {
        println()
        for (index <- 0 until board.size by 3)
          {
            println(" " + board(index) + " | " + board(index+1) + " | " + board(index+2))
            if(6 != index)
            {
              println("---+---+---")
            }
          }
        println()
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