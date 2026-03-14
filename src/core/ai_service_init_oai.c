#include "ai_service_init_oai.h"

#include "services/openai/service_gpt.h"
#include "services/openai/service_embeddings.h"

/*
 * Initialize AIService vtable with the function from the ChatGPT service.
 */
static int initialize_gpt(AIService *ai_service, char *model_name,
						  char *model_description, char *model_url)
{
	/* PG <-> PgAi functions */
	ai_service->init_service_options = gpt_initialize_service;
	ai_service->get_max_request_response_sizes =
		gpt_get_max_request_response_sizes;
	ai_service->set_and_validate_options = gpt_set_and_validate_options;
	ai_service->set_service_data = gpt_set_service_data;
	ai_service->prepare_for_transfer = gpt_prepare_for_transfer;
	ai_service->set_service_buffers = gpt_set_service_buffers;
	ai_service->cleanup_service_data = gpt_cleanup_service_data;
	ai_service->get_service_help = gpt_help;

	/* PgAi <-> REST functions */
	ai_service->rest_transfer = gpt_rest_transfer;
	ai_service->add_rest_headers = gpt_add_rest_headers;
	ai_service->add_rest_data = gpt_add_rest_data;

	/* set the model name and description */
	strcpy(model_name, MODEL_OPENAI_GPT_NAME);
	strcpy(model_description, MODEL_OPENAI_GPT_DESCRIPTION);
	strcpy(model_url, GPT_API_URL);

	return RETURN_ZERO;
}

/*
 * Initialize AIService vtable with functions from the embeddings service.
 */
static int initialize_embeddings(AIService *ai_service, char *model_name,
								 char *model_description, char *model_url)
{
	/* PG <-> PgAi functions */
	ai_service->init_service_options = embeddings_initialize_service;
	ai_service->get_max_request_response_sizes =
		embeddings_get_max_request_response_sizes;
	ai_service->set_and_validate_options = embeddings_set_and_validate_options;
	ai_service->set_service_data = embeddings_set_service_data;
	ai_service->prepare_for_transfer = embeddings_prepare_for_transfer;
	ai_service->set_service_buffers = embeddings_set_service_buffers;
	ai_service->cleanup_service_data = embeddings_cleanup_service_data;
	ai_service->get_service_help = embeddings_help;

	/* PgAi <-> REST functions */
	ai_service->rest_transfer = embeddings_rest_transfer;
	ai_service->add_rest_headers = embeddings_add_rest_headers;
	ai_service->add_rest_data = embeddings_add_rest_data;
	ai_service->process_rest_response = embeddings_process_rest_response;

	/* set the model name and description */
	strcpy(model_name, MODEL_OPENAI_EMBEDDINGS_NAME);
	strcpy(model_description, MODEL_OPENAI_EMBEDDINGS_DESCRIPTION);
	strcpy(model_url, EMBEDDINGS_API_URL);

	return RETURN_ZERO;
}

/*
 * initializes the pointers for the supported OpenAI models
 */
int create_service_oai(size_t model_flags, AIService *ai_service,
					   char *model_name, char *model_description,
					   char *model_url)
{
	int return_value = RETURN_ERROR;

	if (model_flags & MODEL_OPENAI_GPT)
		return_value = initialize_gpt(ai_service, model_name, model_description,
									  model_url);

	if (model_flags & MODEL_OPENAI_EMBEDDINGS)
		return_value = initialize_embeddings(ai_service, model_name,
											 model_description, model_url);

	return return_value;
}
