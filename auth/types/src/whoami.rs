use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Deserialize, Serialize)]
pub struct WhoamiRequest {}

pub type WhoamiResponse = Result<WhoamiResponseBody, WhoamiError>;

#[derive(Debug, Clone, Deserialize, Serialize)]
pub struct WhoamiResponseBody {
    pub username: String,
    pub email: String,
}

#[derive(Debug, Clone, Deserialize, Serialize, thiserror::Error)]
pub enum WhoamiError {
    #[error("missing authorization header")]
    MissingAuthorizationHeader,

    #[error("invalid header encoding: {0}")]
    InvalidHeaderEncoding(String),

    #[error("invalid header syntax")]
    InvalidHeaderSyntax,

    #[error("invalid header schema: {0}")]
    InvalidHeaderSchema(String),

    #[error("invalid token: {0}")]
    InvalidToken(#[from] houseflow_token::Error),

    #[error("token not found in store")]
    TokenNotInStore,

    #[error("user not found")]
    UserNotFound,

    #[error("internal error: `{0}`")]
    InternalError(String),
}

#[cfg(feature = "actix")]
impl actix_web::ResponseError for WhoamiError {
    fn status_code(&self) -> actix_web::http::StatusCode {
        use actix_web::http::StatusCode;

        match self {
            Self::UserNotFound => StatusCode::NOT_FOUND,
            Self::MissingAuthorizationHeader => StatusCode::BAD_REQUEST,
            Self::InvalidHeaderEncoding(_) => StatusCode::BAD_REQUEST,
            Self::InvalidHeaderSyntax => StatusCode::BAD_REQUEST,
            Self::InvalidHeaderSchema(_) => StatusCode::BAD_REQUEST,
            Self::InvalidToken(_) => StatusCode::BAD_REQUEST,
            Self::InternalError(_) => StatusCode::INTERNAL_SERVER_ERROR,
            Self::TokenNotInStore => StatusCode::UNAUTHORIZED,
        }
    }

    fn error_response(&self) -> actix_web::HttpResponse {
        let response = WhoamiResponse::Err(self.clone());
        let json = actix_web::web::Json(response);
        actix_web::HttpResponse::build(self.status_code()).json(json)
    }
}