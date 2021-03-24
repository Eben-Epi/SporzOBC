/*!

\file UiViewFactory.hpp
\brief Factory pour rendre la création des IUiViews générique et rapide
\author Eben
\version 0.1

*/

#include <memory>
#include <map>
#include <iostream>
#include "CoreApp/IGraphicalHandler/IUiView/IUiView.hpp"

#ifndef SPORZOBC_WAL_UIVIEWFACTORY_HPP
#define SPORZOBC_WAL_UIVIEWFACTORY_HPP

//! \interface UiViewFactory
/*!
 * Crée les pages connues par la factory (sUiViews)
 * \sa sUiViews
 */
class UiViewFactory {
public:
    using TCreateMethod = std::unique_ptr<IUiView>(*)();
    TCreateMethod m_CreateFunc;

public:
    UiViewFactory() = delete;

    static bool Register(const std::string name, TCreateMethod createFunc)
    {
        if (auto it = sUiViews.find(name); it == sUiViews.end())
        {
            sUiViews[name] = createFunc;
            std::cout << " registered\n";
            return true;
        }
        return false;
    }

    static std::unique_ptr<IUiView> Create(const std::string& name)
    {
        if (auto it = sUiViews.find(name); it != sUiViews.end())
            return it->second();

        return nullptr;
    }

private:
    //! map des types de pages connus
    static std::map<std::string, TCreateMethod> sUiViews;
};

#endif //SPORZOBC_WAL_UIVIEWFACTORY_HPP
