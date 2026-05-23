pragma Singleton
import QtQuick

QtObject {

    readonly property QtObject config: QtObject {
        readonly property color _color_1      : "white"
        readonly property color _color_2      : "#5d5c61"
        readonly property color _color_3      : "#7395ae"
        readonly property color _color_4      : "#d1cfc9"
        readonly property color _positiveColor: "#6fa36f"
        readonly property color _negativeColor: "#bf5054"
    }


    readonly property color mainWindow: config._color_2

    /* --- Header / Sections --- */
    readonly property color header    : config._color_2
    readonly property color headerText: config._color_1

    /* --- Search --- */
    readonly property string searchIconPath: "qrc:/resources/icons/search.svg"
    readonly property color searchTextInputColor          : config._color_2
    readonly property color searchTextInputBackgroundColor: config._color_1
    readonly property color searchTextColor               : "#999999"
    readonly property color searchSelectionColor          : config._color_3
    readonly property color searchSelectionTextColor      : config._color_1
    // search icon
    readonly property string editIconPath: "qrc:/resources/icons/edit.svg"
    readonly property color editIcon                 : config._color_2
    readonly property color editIconHover            : config._color_1
    readonly property color editIconBackground       : config._color_1
    readonly property color editIconBackgroundHover  : config._color_2
    readonly property color editIconBackgroundPressed: config._color_3

    /* --- Buttons --- */
    // -> Neutral
    // Base
    readonly property color button      : config._color_3
    readonly property color buttonText  : config._color_1
    readonly property color buttonBorder: config._color_3
    // Hover
    readonly property color buttonHover      : config._color_2
    readonly property color buttonTextHover  : config._color_1
    readonly property color buttonBorderHover: config._color_2
    // Pressed
    readonly property color buttonPressed      : config._color_4
    readonly property color buttonTextPressed  : config._color_2
    readonly property color buttonBorderPressed: config._color_2
    // -> Positive
    // Base
    readonly property color buttonPositive      : config._positiveColor
    readonly property color buttonTextPositive  : config._color_1
    readonly property color buttonBorderPositive: config._positiveColor
    // Hover
    readonly property color buttonHoverPositive      : config._color_2
    readonly property color buttonTextHoverPositive  : config._color_1
    readonly property color buttonBorderHoverPositive: config._color_2
    // Pressed
    readonly property color buttonPressedPositive      : config._color_4
    readonly property color buttonTextPressedPositive  : config._color_2
    readonly property color buttonBorderPressedPositive: config._color_2
    // -> Negative
    // Base
    readonly property color buttonNegative      : config._negativeColor
    readonly property color buttonTextNegative  : config._color_1
    readonly property color buttonBorderNegative: config._negativeColor
    // Hover
    readonly property color buttonHoverNegative      : config._color_2
    readonly property color buttonTextHoverNegative  : config._color_1
    readonly property color buttonBorderHoverNegative: config._color_2
    // Pressed
    readonly property color buttonPressedNegative      : config._color_4
    readonly property color buttonTextPressedNegative  : config._color_2
    readonly property color buttonBorderPressedNegative: config._color_2

    /* --- Buttons end --- */

    // Base
    readonly property color background: config._color_4
    readonly property color panel     : config._color_4

    // ListView
    readonly property color listView : config._color_1
    // delegate of listView
    readonly property color listItem           : config._color_1
    readonly property color listItemHover      : config._color_2
    readonly property color listItemPressed    : config._color_3
    readonly property color listItemText       : config._color_2
    readonly property color listItemTextHover  : config._color_1
    readonly property color listItemTextPressed: config._color_1

    readonly property int spacing: 8

    readonly property int animationDuration: 100
}
