#include "StdAfx.h"
#include "Creceiver.h"
#include "Cinterpreter.h"
#include "unicodeReader.h"

Cinterpreter::Cinterpreter(void)
{
}


Cinterpreter::~Cinterpreter(void)
{
}


int Cinterpreter::m_getProjects()
{
		int Count = 0;
		SdaiIterator ProjectIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcProject");
		while (SdaiInstance IFCProjectInstance = sdaiextGetInstanceByIterator(ProjectIterator))
		{
			Count++;
			m_getProject(IFCProjectInstance);
		}
	//возвращаем кол-во проектов (счетчик)
	return Count;
}

int Cinterpreter::m_getBuilding(void)
{
	
	return true;
}
int Cinterpreter::m_getProject(SdaiInstance &IFCProjectInstance)
{
	

	if(IFCProjectInstance)
	 {
		 /*if (m_Receiver && m_Receiver->m_Function)
		m_Receiver->m_Function;*/
		// SdaiIterator RootIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcRoot");

						SdaiString Str = nullptr;
							
						sdaiGetAttrBN(IFCProjectInstance, "Name", sdaiSTRING, &Str);
						Str = UnicodeRead(Str);
						
					m_Receiver->m_Function(Str);

					int WallsCount = m_getWall();
	 }
	
	//было наверху
	
	// получили проект, есть куча атрибутов , перебираем атрибуты, получаем значения, некоторые атрибуты не нужны, экземпляр ресивeра и будет определять какие атрибуты ресивера нам нужны а какие нет
	//  некоторые атрибуты через колбеки мы будем посылать в вокер
				//	

				//ENTITY IfcRoot
					//GlobalId	:	IfcGloballyUniqueId;
					//OwnerHistory	:	OPTIONAL IfcOwnerHistory;
					//Name	:	OPTIONAL IfcLabel;
					//Description	:	OPTIONAL IfcText;
				//ENTITY IfcObjectDefinition
					//INVERSE
					//HasAssignments	:	SET OF IfcRelAssigns FOR RelatedObjects;
					//Nests	:	SET [0:1] OF IfcRelNests FOR RelatedObjects;
					//IsNestedBy	:	SET OF IfcRelNests FOR RelatingObject;
					//HasContext	:	SET [0:1] OF IfcRelDeclares FOR RelatedDefinitions;
					//IsDecomposedBy	:	SET OF IfcRelAggregates FOR RelatingObject;
					//Decomposes	:	SET [0:1] OF IfcRelAggregates FOR RelatedObjects;
					//HasAssociations	:	SET OF IfcRelAssociates FOR RelatedObjects;
				//ENTITY IfcContext
					//ObjectType	:	OPTIONAL IfcLabel;
					//LongName	:	OPTIONAL IfcLabel;
					//Phase	:	OPTIONAL IfcLabel;
					//RepresentationContexts	:	OPTIONAL SET [1:?] OF IfcRepresentationContext;
					//UnitsInContext	:	OPTIONAL IfcUnitAssignment;
					//INVERSE
					//IsDefinedBy	:	SET [0:?] OF IfcRelDefinesByProperties FOR RelatedObjects;
					//Declares	:	SET OF IfcRelDeclares FOR RelatingContext;
				//
//ENTITY IfcProject
//END_ENTITY;
	return 0;
}


int Cinterpreter::m_getSite(void)
{

	//тоже атрибуты участка
	//возвращают некоторый идентификатор того что создано конвертером (либо указатель либо идентификатор- индекс)
	return 0;
	//для универсальности
}


int Cinterpreter::m_getWall(void)
{
	//стены
	 int ItemCount = 0;
	//заходим в пункт со стенами
	SdaiIterator NodeIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcWallStandardCase");
	//итератор, который идет по папке стен
	while(SdaiInstance STEPNodeInstance = sdaiextGetInstanceByIterator(NodeIterator))
	{
     SdaiInstance ObjectPlacementInstance = NULL;
	 sdaiGetAttrBN(STEPNodeInstance, "ObjectPlacement", sdaiINSTANCE, &ObjectPlacementInstance);
	 SdaiInstance RelativePlacementInstance = NULL;
	 sdaiGetAttrBN(ObjectPlacementInstance, "RelativePlacement", sdaiINSTANCE, &RelativePlacementInstance);
	 SdaiInstance LocationInstance = NULL;
	 SdaiReal Coords [3] = {0.0, 0.0, 0.0};
//координаты
	 sdaiGetAttrBN(RelativePlacementInstance, "Location", sdaiINSTANCE, &LocationInstance);
	 if(LocationInstance)
	 {
	 SdaiIterator CoordIterator = sdaiextGetAttributeIterator(LocationInstance, "Coordinates");
	   sdaiBeginning(CoordIterator);
	   sdaiNext(CoordIterator);
	   sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [0]);
	   sdaiNext(CoordIterator);
	   sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [1]);
	   sdaiNext(CoordIterator);
	   sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [2]);
	   sdaiDeleteIterator(CoordIterator);
	 }
	 //направление
	 SdaiInstance RefDirectionInstance = NULL;
	 SdaiReal Directions [2] = {1.0, 0.0};
	 sdaiGetAttrBN(RelativePlacementInstance, "RefDirection", sdaiINSTANCE, &RefDirectionInstance);
	 if(RefDirectionInstance)
	 {
	 SdaiIterator DirectionIterator = sdaiextGetAttributeIterator(RefDirectionInstance, "DirectionRatios");
	   sdaiBeginning(DirectionIterator);
	   sdaiNext(DirectionIterator);
	   sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Directions [0]);
	   sdaiNext(DirectionIterator);
	   sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Directions [1]);
	   sdaiDeleteIterator(DirectionIterator);
	 }
	// sdaiNext(NodeIterator);
	 // длина
	  SdaiInstance RepresentationInstance = NULL;
	 sdaiGetAttrBN(STEPNodeInstance, "Representation", sdaiINSTANCE, &RepresentationInstance);
//	  if(RepresentationInstance)
	// {
	 SdaiIterator RepresentationIterator = sdaiextGetAttributeIterator(RepresentationInstance, "Representations");
	 sdaiBeginning(RepresentationIterator);
	  //СДЕЛАТЬ ЦИКЛ, ЧТОБЫ УЧЕСТЬ РАЗНЫЕ СИСТЕМЫ
	 //ЕСЛИ ЭТО МОЙ ШЕЙПРЕПРЕЗЕНТЕЙШН ТО ОБРАБАТЫВАЮ
	 //ЕСЛИ НЕ ТОТ ТО СДЕЛАТЬ ПУСТЫШКУ
	 sdaiNext(RepresentationIterator);
	   sdaiNext(RepresentationIterator);
						SdaiInstance ShapeRepresentationInstance=0;
						sdaiGetAggrByIterator(RepresentationIterator, sdaiINSTANCE, &ShapeRepresentationInstance);
						SdaiIterator ItemsIterator = sdaiextGetAttributeIterator(ShapeRepresentationInstance, "Items");
						sdaiBeginning(ItemsIterator);
						sdaiNext(ItemsIterator);
						SdaiInstance ExtrudedAreaInstance=0;
						sdaiGetAggrByIterator(ItemsIterator, sdaiINSTANCE, &ExtrudedAreaInstance);
								SdaiInstance SweptAreaInstance = NULL;
								sdaiGetAttrBN(ExtrudedAreaInstance, "SweptArea", sdaiINSTANCE, &SweptAreaInstance);
									SdaiReal Length = 0.0;
									sdaiGetAttrBN(SweptAreaInstance, "XDim", sdaiREAL, &Length);
									 
									  sdaiDeleteIterator(ItemsIterator);
									   sdaiDeleteIterator(RepresentationIterator);

	}
	sdaiDeleteIterator(NodeIterator);

	return 0;
	
}

int Cinterpreter::m_getStorey(void)
{
	//этаж
	//возвращают некоторый идентификатор того что создано конвертером 
	return 0;
}

//сделать ресивер который через коллбеки передать наверх имя проекта, взять из ифс проджект 
//выдать название проекта в форму
//колбек функция принимает строку с именем проекта, а ресивер у него есть адрес той колбек функции
//ее назовет сетпроджекттайтл
//ресивер получает адрес колбек функции
//в гетпроджект посылаем адрес ресивера ,т.е. добавляем в параметр экземляр ресивера
//обработчик смотрит есть ли у колбек функции адрес и если есть то она вытаскивает значение атрибута из модели и вызывает эту коллбек функцию
//тела функций в верхней, адреса функций в ресивере, а пользоваться ими будет интерпретер, интерпретер знает про ресивер и может пользоваться его переменными
//у ресивера есть ресет колбек функций 