
#include "ViewModel.h"
#include "ChildViewer.h"


ViewModel::ViewModel(ChildViewer* ChildViewer) : m_ChildViewer(ChildViewer), m_kit(NULL)
{
    m_kit = new PDFkit();

    // todo待重构
    QString strFileName = m_ChildViewer->getFileName();
    m_kit->SetFileName(strFileName);
    m_kit->Init();

    m_ViewState = new SingleContinuousState(m_ChildViewer);

}

ViewModel::~ViewModel()
{

}

int ViewModel::GetActruallyPageHighCount()
{
    int nPageHighCount = 0;
    for (int i = 0; i < GetNumCount(); i++)
        nPageHighCount += GetActruallyPageSize(i).height();

    return nPageHighCount;
}

void ViewModel::RenderPages(QPainter *painter)
{
    if (painter == NULL || m_ViewState == NULL)
        return;

//    QImage image1 = GetImage();
//    painter->drawImage(0, GetVScrollPos(),image1);
    m_ViewState->RenderPages(painter);

}




