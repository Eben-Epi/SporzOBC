/*!

\file UiViewFactory.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_UIVIEWFACTORY_HPP
#define SPORZOBC_WAL_UIVIEWFACTORY_HPP

#include <map>
#include <memory>
#include <string>
#include "CoreApp/IGraphicalHandler/IUiView/IUiView.hpp"
#include "CoreApp/GameLogicManager/GameLogicManager.hpp"

enum UiViews {
    NO_VIEW,
    CALCULATOR
};

class UiViewFactory {
public:
    using TCreateMethod = std::unique_ptr<IUiView>(*)();

    UiViewFactory() = delete;

    static bool Register(UiViews name, TCreateMethod funcCreate);

    static std::unique_ptr<IUiView> Create(UiViews name);
    static std::unique_ptr<IUiView> Create(UiViews name, const std::unique_ptr<GameLogicManager>& glm);

private:
    static std::map<UiViews, TCreateMethod>& s_methods();
};

template <typename T>
class RegisteredInFactory
{
protected:
    RegisteredInFactory() { s_bRegistered; }
    static bool s_bRegistered;
};

template <typename T>
bool RegisteredInFactory<T>::s_bRegistered =
        UiViewFactory::Register(T::GetFactoryName(), T::CreateMethod);

#endif //SPORZOBC_WAL_UIVIEWFACTORY_HPP
