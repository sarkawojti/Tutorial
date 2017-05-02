trait IParser {  def parse(file_name : String) }

class Parser() extends IParser 
{
    private var parser : IParser = _
    override def parse(file_name : String) = 
    {
        println("Try parse file : " + file_name)
        if(null != parser) 
        {
            parser.parse(file_name)
        }
        else
        {
            println("First set parse strategy!")
        }
        println("Finish parse file : " + file_name)
    }
    
    def strategy(_parser : IParser) = 
    {
        parser = _parser
    }
}

class CvsParser() extends IParser {
    private var _file_regex = "([A-Za-z]+).cvs".r
    
    override def parse(file_name : String) = 
    {
        if(_file_regex.pattern.matcher(file_name).matches)
        {
            println("Parse file: " + file_name)
        }
        else
        {
            println("Wrong file format [expected: *.cvs]")  
        }
    }
}

class JsonParser() extends IParser {
    private var _file_regex = "([A-Za-z]+).json".r
    
    override def parse(file_name : String) = 
    {
        if(_file_regex.pattern.matcher(file_name).matches)
        {
            println("Parse file: " + file_name)
        }
        else
        {
            println("Wrong file format [expected: *.json]")  
        }
    }
}


var parser  = new Parser
var parser_json : IParser = new JsonParser
var parser_cvs : IParser = new CvsParser

parser.strategy(parser_json)
parser.parse("data.json")

parser.strategy(parser_cvs)
parser.parse("data.cvs")