
#include "inc/ConsolLogger.h"
#include "inc/FileLogger.h"
#include "inc/LevelConsolLogger.h"
#include "inc/LevelFileLogger.h"
#include "inc/LevelLogger.h"

#include <memory>

int main()
{
    std::shared_ptr<ILogger> consol_logger =
        std::make_shared<ConsolLogger>();
    consol_logger->log("Error", "............................");
    consol_logger->log("Warning", "............................");
    consol_logger->log("Info", "............................");
    consol_logger->log("Debug", "............................");

    /** adapter klasowy **/
    std::shared_ptr<ILevelLogger> level_consol_logger =
        std::make_shared<LevelConsolLogger>();
    level_consol_logger->error("............................");
    level_consol_logger->warning("............................");
    level_consol_logger->info("............................");
    level_consol_logger->debug("............................");

    /** adapter obiektowy **/
    std::shared_ptr<ILevelLogger> level_logger =
        std::make_shared<LevelLogger>(consol_logger);
    level_logger->error("............................");
    level_logger->warning("............................");
    level_logger->info("............................");
    level_logger->debug("............................");



    std::shared_ptr<ILogger> file_logger =
        std::make_shared<FileLogger>("logs.txt");
    file_logger->log("Error", "............................");
    file_logger->log("Warning", "............................");
    file_logger->log("Info", "............................");
    file_logger->log("Debug", "............................");

    /** adapter klasowy **/
    std::shared_ptr<ILevelLogger> level_file_logger =
        std::make_shared<LevelFileLogger>("logs.txt");
    level_file_logger->error("............................");
    level_file_logger->warning("............................");
    level_file_logger->info("............................");
    level_file_logger->debug("............................");

    /** adapter obiektowy **/
    level_logger =
        std::make_shared<LevelLogger>(file_logger);
    level_logger->error("............................");
    level_logger->warning("............................");
    level_logger->info("............................");
    level_logger->debug("............................");

    return 0;
}
