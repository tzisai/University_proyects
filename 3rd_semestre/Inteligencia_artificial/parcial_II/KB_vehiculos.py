kb_vehiculos = [
    {
        "rule_name": "bicycle",
        "if": [
            {"variable": "vehicleType", "value": "cycle"},
            {"variable": "num_wheels", "value": 2},
            {"variable": "motor", "value": "no"}
        ],
        "then": {"variable": "vehicle", "value": "Bicicleta"}
    },
    {
        "rule_name": "tricycle",
        "if": [
            {"variable": "vehicleType", "value": "cycle"},
            {"variable": "num_wheels", "value": 3},
            {"variable": "motor", "value": "no"}
        ],
        "then": {"variable": "vehicle", "value": "Triciclo"}
    },
    {
        "rule_name": "motorcycle",
        "if": [
            {"variable": "vehicleType", "value": "cycle"},
            {"variable": "num_wheels", "value": 2},
            {"variable": "motor", "value": "yes"}
        ],
        "then": {"variable": "vehicle", "value": "Motocicleta"}
    },
    {
        "rule_name": "sports_car",
        "if": [
            {"variable": "vehicleType", "value": "automobile"},
            {"variable": "size", "value": "small"},
            {"variable": "num_doors", "value": 2}
        ],
        "then": {"variable": "vehicle", "value": "Auto Deportivo"}
    },
    {
        "rule_name": "minivan",
        "if": [
            {"variable": "vehicleType", "value": "automobile"},
            {"variable": "size", "value": "medium"},
            {"variable": "num_doors", "value": 3}
        ],
        "then": {"variable": "vehicle", "value": "Minivan"}
    },
    {
        "rule_name": "suv",
        "if": [
            {"variable": "vehicleType", "value": "automobile"},
            {"variable": "size", "value": "large"},
            {"variable": "num_doors", "value": 4}
        ],
        "then": {"variable": "vehicle", "value": "SUV"}
    },
    {
        "rule_name": "convertible",
        "if": [
            {"variable": "vehicleType", "value": "automobile"},
            {"variable": "size", "value": "small"},
            {"variable": "num_doors", "value": 2},
            {"variable": "roof", "value": "retractable"}
        ],
        "then": {"variable": "vehicle", "value": "Convertible"}
    },
    {
        "rule_name": "pickup_truck",
        "if": [
            {"variable": "vehicleType", "value": "automobile"},
            {"variable": "size", "value": "large"},
            {"variable": "cargo_bed", "value": "yes"}
        ],
        "then": {"variable": "vehicle", "value": "Camioneta Pickup"}
    },
]
