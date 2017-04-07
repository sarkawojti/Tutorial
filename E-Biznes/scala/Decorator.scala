import java.io.{BufferedReader, InputStreamReader}
import scala.io.StdIn.readLine

import scala.collection.JavaConverters._

trait Reader {  def read(): String }

class FileReader(filename: String) extends Reader {
  val contents = {
    val stream = this.getClass.getResourceAsStream(filename)
    val reader = new BufferedReader(
      new InputStreamReader(
        stream
      )
    )
    try {
      reader.lines().iterator().asScala.mkString(System.getProperty("line.separator"))
    } finally {
      reader.close()
      stream.close()
    }
  }
  override def read(): String = contents
}

class InputReader(command_name: String) extends Reader {
  val contents = {
    print(command_name)
    readLine()
  }
  override def read(): String = contents
}

abstract class ReaderDecorator(_reader : Reader) extends Reader{
  protected var reader: Reader = _reader
}

class ReaderWhiteSpaceClean(reader: Reader) extends ReaderDecorator(reader){
  override def read(): String = {
    reader.read().replace(" ", "")
  }
}

class ReaderUpperCase(reader: Reader) extends ReaderDecorator(reader){
  override def read(): String = {
    reader.read().toUpperCase()
  }
}

object Main
{
  def main(args: Array[String]): Unit =
  {
    var file_reader = new FileReader("file1")
    println(file_reader.read())

    var file_reader_white_space_clean = new ReaderWhiteSpaceClean(file_reader)
    println(file_reader_white_space_clean.read())

    var file_reader_upper_case = new ReaderUpperCase(file_reader)
    println(file_reader_upper_case.read())

    var input_reader = new InputReader("haslo: ")
    println(input_reader.read())

    file_reader_white_space_clean = new ReaderWhiteSpaceClean(input_reader)
    println(file_reader_white_space_clean.read())

    file_reader_upper_case = new ReaderUpperCase(input_reader)
    println(file_reader_upper_case.read())
  }
}

