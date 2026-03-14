#ifndef _OPENAI_CONFIG_H_
#define _OPENAI_CONFIG_H_

/* -----------------8< gpt service ---------- */
/*
 * "instruct" is better at answering pointed questions and "gpt"
 * in general is chatty
 */
#define MODEL_OPENAI_GPT_NAME "gpt-3.5-turbo-instruct"
#define MODEL_OPENAI_GPT_DESCRIPTION                                           \
	"GPT Model for answering pointed questions."

#define GPT_API_URL "https://api.openai.com/v1/completions"
#define GPT_SUMMARY_PROMPT "Get summary of the following in 1 lines."
#define GPT_AGG_PROMPT "Suggest a topic for the following."

#define RESPONSE_JSON_CHOICE "choices"
#define RESPONSE_JSON_KEY "text"

#define GPT_HELP INSIGHT_FUNCTIONS

/* -----------------gpt service >8---------- */

/* -----------------8< embeddings service ---------- */
#define MODEL_OPENAI_EMBEDDINGS_NAME "text-embedding-ada-002"
#define MODEL_OPENAI_EMBEDDINGS_DESCRIPTION "OpenAI's embeddings model(vectors)"

#define EMBEDDINGS_API_URL "https://api.openai.com/v1/embeddings"

#define EMBEDDINGS_HELP EMBEDDING_FUNCTIONS

/*  seems const - TODO */
#define EMBEDDINGS_LIST_SIZE 1536
/* ----------------- embeddings service >8---------- */

#endif /* _OPENAI_CONFIG_H_ */
