#Add end of file
import app
if app.__BL_SAFEBOX_MONEY__:
	window["children"][0]["children"] += (
		{
			"name":"Money_Slot",
			"type":"button",

			"x":8,
			"y":110,

			"horizontal_align":"center",
			"vertical_align":"bottom",

			"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
			"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
			"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

			"children" :
			(
				{
					"name":"Money_Icon",
					"type":"image",

					"x":-18,
					"y":2,

					"image":"d:/ymir work/ui/game/windows/money_icon.sub",
				},

				{
					"name" : "Money",
					"type" : "text",

					"x" : 3,
					"y" : 3,

					"horizontal_align" : "right",
					"text_horizontal_align" : "right",

					"text" : "123456789",
				},
			),
		},
	)