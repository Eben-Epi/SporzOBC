#include <QApplication>
#include <iostream>
#include "CoreApp/CoreApp.hpp"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

int main(int argc, char **argv)
{
    try {
        QApplication app(argc, argv);
        CoreApp appSporz;
        appSporz.startNewGame();
        auto GLM = appSporz.getGameLogicManagerInstance().get();
        std::cout << GLM->getPlayerCount() << std::endl;
        auto CalculatorPage = UiViewFactory::Create(CALCULATOR);

        GLM->setPlayerCount(7);
        std::cout << GLM->getPlayerCount() << std::endl;
        GLM->setPlayerName(6, "Tom");
        std::cout << GLM->getPlayerName(6) << std::endl;
        std::cout << GLM->getPlayerName(7) << std::endl;
        GLM->setPlayerCount(6);
        std::cout << GLM->getPlayerName(7) << std::endl;
        CalculatorPage->showUi();
        return app.exec();
    } catch (SporzException& e) {
        std::cout << e.what();
    }
}
