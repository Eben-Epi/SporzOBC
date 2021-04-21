/*!

\file UiViewFactory.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

std::map<UiViews, UiViewFactory::TCreateMethod>& UiViewFactory::s_methods() {
    static std::map<UiViews, UiViewFactory::TCreateMethod> my_static_obj_;
    return my_static_obj_;
};

bool UiViewFactory::Register(UiViews name,
                                        TCreateMethod funcCreate)
{
    if (auto it = s_methods().find(name); it == s_methods().end())
    {
        s_methods()[name] = funcCreate;
        return true;
    }
    return false;
}

std::unique_ptr<IUiView> UiViewFactory::Create(UiViews name)
{
    if (auto it = s_methods().find(name); it != s_methods().end())
        return it->second();

    return nullptr;
}