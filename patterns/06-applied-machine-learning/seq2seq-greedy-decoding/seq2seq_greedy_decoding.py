# Pattern: Greedy decoding of a sequence-to-sequence model
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/machine-learning-practices -> src/project-seq2seq-chatbot.ipynb (notebook cells defining decode_sequence)
#          https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/project-seq2seq-chatbot.ipynb#L1
# Extract: selected code cells, concatenated in notebook order; output and narrative cells removed.
#          Not a standalone build. See the source repository for the
#          full build context.


# MODELO ENCODER (Solo procesa la entrada y devuelve los estados)
encoder_model = Model(encoder_inputs, encoder_states)

# MODELO DECODER (Generación paso a paso)
# Necesitamos nuevas capas de entrada (Input) para inyectar los estados ocultos en cada paso del bucle
decoder_state_input_h = Input(shape=(latent_dim,), name="input_h_inferencia")
decoder_state_input_c = Input(shape=(latent_dim,), name="input_c_inferencia")
decoder_states_inputs = [decoder_state_input_h, decoder_state_input_c]

# Reutilizamos la misma capa LSTM entrenada, pero le pasamos los nuevos estados de entrada
decoder_outputs_inf, state_h_inf, state_c_inf = decoder_lstm(
    decoder_inputs, initial_state=decoder_states_inputs
)
decoder_states_inf = [state_h_inf, state_c_inf]

# Reutilizamos la misma capa Dense (Softmax) entrenada para predecir el token
decoder_outputs_inf = decoder_dense(decoder_outputs_inf)

# Ensamblamos el modelo Decoder final de inferencia
decoder_model = Model(
    [decoder_inputs] + decoder_states_inputs,  # Entradas: el token anterior + los estados
    [decoder_outputs_inf] + decoder_states_inf # Salidas: el nuevo token + los nuevos estados
)

#Bucle de inferencia para generar textos
def decode_sequence(input_seq):
    # El Encoder lee la pregunta y extrae el vector de contexto (estados)
    states_value = encoder_model.predict(input_seq, verbose=0)

    # Creamos una secuencia de entrada vacía (tamaño 1x1xNum_Tokens)
    target_seq = np.zeros((1, 1, num_decoder_tokens))
    # La inicializamos inyectando el token de inicio (tabulador '\t')
    target_seq[0, 0, target_token_index['\t']] = 1.0

    stop_condition = False
    decoded_sentence = ""

    # BUCLE MANUAL DE GENERACIÓN
    while not stop_condition:
        # El Decoder predice el siguiente carácter basado en el anterior y los estados
        output_tokens, h, c = decoder_model.predict([target_seq] + states_value, verbose=0)

        # Obtenemos el índice del carácter con mayor probabilidad (argmax)
        sampled_token_index = np.argmax(output_tokens[0, -1, :])
        sampled_char = reverse_target_char_index[sampled_token_index]

        # Añadimos el carácter predicho a la frase final
        decoded_sentence += sampled_char

        # Condición de parada: Si predice '\n' o si la frase es demasiado larga
        if sampled_char == '\n' or len(decoded_sentence) > max_decoder_seq_length:
            stop_condition = True

        # Preparamos la entrada para el siguiente paso temporal (vaciamos e inyectamos el nuevo carácter)
        target_seq = np.zeros((1, 1, num_decoder_tokens))
        target_seq[0, 0, sampled_token_index] = 1.0

        # Actualizamos los estados internos de la red
        states_value = [h, c]

    return decoded_sentence

# Prueba de Inferencia
print("\n--- CHATBOT SPIDER-MAN ---")
print("-" * 40)
for seq_index in range(len(input_texts)): # Probamos con las 10 frases originales
    # Seleccionamos la secuencia en formato One-Hot
    input_seq = encoder_input_data[seq_index: seq_index + 1]

    # Generamos la respuesta con nuestro bucle
    decoded_sentence = decode_sequence(input_seq)

    print("- Pregunta (Usuario):", input_texts[seq_index])
    print("- Respuesta (Bot):   ", decoded_sentence.strip()) # strip() quita los \t y \n visuales
    print("-" * 40)
