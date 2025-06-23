kb_deportes = [
    {
        "rule_name": "futbol",
        "if": [
            {"variable": "num_jugadores", "value": 11},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "cesped"},
            {"variable": "tipo_cancha", "value": "rectangular"}
        ],
        "then": {"variable": "deporte", "value": "futbol"}
    },
    {
        "rule_name": "baloncesto",
        "if": [
            {"variable": "num_jugadores", "value": 5},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "superficie dura"},
            {"variable": "tipo_cancha", "value": "rectangular"}
        ],
        "then": {"variable": "deporte", "value": "baloncesto"}
    },
    {
        "rule_name": "beisbol",
        "if": [
            {"variable": "num_jugadores", "value": 9},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "cesped"},
            {"variable": "tipo_cancha", "value": "diamante"},
            {"variable": "equipo", "value": "bates"}
        ],
        "then": {"variable": "deporte", "value": "beisbol"}
    },
    {
        "rule_name": "tenis",
        "if": [
            {"variable": "num_jugadores", "value": 2},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "superficie dura"},
            {"variable": "tipo_cancha", "value": "rectangular"},
            {"variable": "equipo", "value": "raquetas"}
        ],
        "then": {"variable": "deporte", "value": "tenis"}
    },
    {
        "rule_name": "hockey_hielo",
        "if": [
            {"variable": "num_jugadores", "value": 6},
            {"variable": "balon", "value": "no"},
            {"variable": "cancha", "value": "hielo"},
            {"variable": "tipo_cancha", "value": "rectangular"},
            {"variable": "equipo", "value": "palos"}
        ],
        "then": {"variable": "deporte", "value": "Hockey sobre Hielo"}
    },
    {
        "rule_name": "voleibol",
        "if": [
            {"variable": "num_jugadores", "value": 6},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "arena"},
            {"variable": "tipo_cancha", "value": "rectangular"}
        ],
        "then": {"variable": "deporte", "value": "Voleibol de playa"}
    },
    {
        "rule_name": "golf",
        "if": [
            {"variable": "num_jugadores", "value": 1},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "cesped"},
            {"variable": "equipo", "value": "palos"},
            {"variable": "tipo_cancha", "value": "campo_abierto"}
        ],
        "then": {"variable": "deporte", "value": "Golf"}
    },
    {
        "rule_name": "rugby",
        "if": [
            {"variable": "num_jugadores", "value": 15},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "cesped"},
            {"variable": "tipo_cancha", "value": "rectangular"}
        ],
        "then": {"variable": "deporte", "value": "Rugby"}
    },
    {
        "rule_name": "ping_pong",
        "if": [
            {"variable": "num_jugadores", "value": 2},
            {"variable": "balon", "value": "si"},
            {"variable": "cancha", "value": "mesa"},
            {"variable": "equipo", "value": "paletas"}
        ],
        "then": {"variable": "deporte", "value": "Ping Pong"}
    },
    {
        "rule_name": "boxeo",
        "if": [
            {"variable": "num_jugadores", "value": 2},
            {"variable": "balon", "value": "no"},
            {"variable": "cancha", "value": "ring"},
            {"variable": "equipo", "value": "guantes"}
        ],
        "then": {"variable": "deporte", "value": "Boxeo"}
    }
]