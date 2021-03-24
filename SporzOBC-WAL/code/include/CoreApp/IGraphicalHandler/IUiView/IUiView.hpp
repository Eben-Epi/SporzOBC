/*!

\file IUiView.hpp
\brief Interface générique pour une page de l'application
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_IUIVIEW_HPP
#define SPORZOBC_WAL_IUIVIEW_HPP

//! \interface IUiView
class IUiView {
public:
    IUiView() = default;

    virtual ~IUiView() = default;

    virtual void showUi() = 0;
};
#endif //SPORZOBC_WAL_IUIVIEW_HPP
